// Editor-title and status-bar buttons for the local LeetCode C++ workspace.
// A problem is X.cpp (solution), X.md (description) and X.test.cpp (tests);
// every button works from any of the three.
const vscode = require('vscode');
const path = require('path');
const fs = require('fs');
const os = require('os');
const crypto = require('crypto');

const BUILD_TASK = 'LeetCode: build active file';
const BUILD_DIR = path.join(require('os').homedir(), 'Library/Caches/leetcode_cpp');
const ANALYSIS_RUNNER = path.join(__dirname, 'analyze.sh');
let analysisPanel;
let analysisPoll;

function problemBase(uri) {
    return uri.fsPath.replace(/\.md$/, '').replace(/\.cpp$/, '').replace(/\.test$/, '');
}

async function activeProblem() {
    const editor = vscode.window.activeTextEditor;
    if (!editor) return undefined;
    await vscode.workspace.saveAll(false);
    const folder = vscode.workspace.getWorkspaceFolder(editor.document.uri);
    return { base: problemBase(editor.document.uri), folder };
}

function shellQuote(value) {
    return `'${String(value).replace(/'/g, `'\\''`)}'`;
}

function reportTitle(base) {
    return path.basename(base).replace(/[\\/:*?"<>|]/g, '-');
}

function reportPath(base, provider, folder) {
    return path.join(folder.uri.fsPath, 'Questions', reportTitle(base), `analysis.${provider}.md`);
}

function fingerprintFor(base, provider) {
    const hash = crypto.createHash('sha256');
    for (const suffix of ['.cpp', '.md', '.test.cpp']) {
        const file = `${base}${suffix}`;
        hash.update(suffix);
        hash.update(fs.existsSync(file) ? fs.readFileSync(file) : '');
    }
    hash.update('benchmark:clang++-c++23-O2-DNDEBUG-no-sanitizers');
    hash.update(`provider:${provider}`);
    return hash.digest('hex');
}

function cachedAnalysis(file, fingerprint) {
    if (!fs.existsSync(file)) return false;
    const header = fs.readFileSync(file, 'utf8').split(/\r?\n/, 1)[0];
    return header.includes(`fingerprint=${fingerprint}`);
}

function escapeHtml(value) {
    return value.replace(/[&<>"']/g, ch => ({
        '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;'
    }[ch]));
}

function inlineHtml(value) {
    let text = value
        .replace(/\\\(/g, '(')
        .replace(/\\\)/g, ')');
    const tokens = [];
    const protect = html => {
        tokens.push(html);
        return `\u0000${tokens.length - 1}\u0000`;
    };

    text = text
        .replace(/\\Theta/g, 'Θ')
        .replace(/\\Omega/g, 'Ω')
        .replace(/\\Delta/g, 'Δ')
        .replace(/\\leq?/g, '≤')
        .replace(/\\geq?/g, '≥')
        .replace(/\\cdot/g, '·')
        .replace(/\\times/g, '×')
        .replace(/\\in/g, '∈')
        .replace(/([A-Za-z0-9)\]])\^\{([^{}]+)\}/g, (_, base, exponent) => `${base}${protect(`<sup>${escapeHtml(exponent)}</sup>`)}`)
        .replace(/\^\{([^{}]+)\}/g, (_, exponent) => protect(`<sup>${escapeHtml(exponent)}</sup>`));
    text = text.replace(/\\/g, '');

    text = text.replace(/`([^`]+)`/g, (_, content) => {
        return protect(`<code>${escapeHtml(content)}</code>`);
    });
    text = escapeHtml(text)
        .replace(/\*\*([^*]+)\*\*/g, '<strong>$1</strong>')
        .replace(/__([^_]+)__/g, '<strong>$1</strong>')
        .replace(/\*([^*]+)\*/g, '<em>$1</em>')
        .replace(/\u0000(\d+)\u0000/g, (_, index) => tokens[Number(index)]);
    return text;
}

function markdownHtml(markdown) {
    const lines = markdown.replace(/^<!--.*-->\s*/m, '').split(/\r?\n/);
    let html = '';
    let inList = false;
    let inCode = false;
    for (const raw of lines) {
        if (raw.trim().startsWith('```')) {
            html += inCode ? '</code></pre>' : '<pre><code>';
            inCode = !inCode;
            continue;
        }
        if (inCode) { html += escapeHtml(raw) + '\n'; continue; }
        const line = inlineHtml(raw);
        if (!line.trim()) {
            if (inList) { html += '</ul>'; inList = false; }
            continue;
        }
        const heading = line.match(/^(#{1,3})\s+(.*)$/);
        if (heading) {
            if (inList) { html += '</ul>'; inList = false; }
            const level = heading[1].length;
            html += `<h${level}>${heading[2]}</h${level}>`;
        } else if (/^[-*]\s+/.test(line)) {
            if (!inList) { html += '<ul>'; inList = true; }
            html += `<li>${line.replace(/^[-*]\s+/, '')}</li>`;
        } else {
            if (inList) { html += '</ul>'; inList = false; }
            html += `<p>${line}</p>`;
        }
    }
    if (inList) html += '</ul>';
    if (inCode) html += '</code></pre>';
    return html;
}

function showAnalysis(file, title, provider) {
    const markdown = fs.readFileSync(file, 'utf8');
    if (analysisPanel) analysisPanel.dispose();
    analysisPanel = vscode.window.createWebviewPanel(
        'leetcodeAnalysis', `${title} — ${provider} analysis`, vscode.ViewColumn.Beside,
        { enableScripts: true, retainContextWhenHidden: true }
    );
    analysisPanel.webview.html = `<!doctype html><html><head><meta charset="UTF-8">
<style>
body { padding: 0 24px 32px; color: var(--vscode-editor-foreground); font-family: var(--vscode-font-family); line-height: 1.55; }
header { position: sticky; top: 0; background: var(--vscode-editor-background); padding: 14px 0 10px; border-bottom: 1px solid var(--vscode-panel-border); }
h1,h2,h3 { font-weight: 600; } h1 { font-size: 1.35em; } h2 { margin-top: 26px; font-size: 1.1em; }
code { background: var(--vscode-textCodeBlock-background); padding: 1px 4px; border-radius: 3px; }
pre { padding: 12px; overflow: auto; background: var(--vscode-textCodeBlock-background); }
button { float: right; color: var(--vscode-button-foreground); background: var(--vscode-button-background); border: 0; padding: 5px 12px; cursor: pointer; border-radius: 3px; }
</style></head><body><header><button id="close">Close</button><strong>${escapeHtml(title)} · ${escapeHtml(provider)}</strong></header>${markdownHtml(markdown)}
<script>const vscode = acquireVsCodeApi(); document.getElementById('close').onclick = () => vscode.postMessage({command:'close'});</script>
</body></html>`;
    analysisPanel.webview.onDidReceiveMessage(message => {
        if (message.command === 'close') analysisPanel.dispose();
    }, null, []);
    analysisPanel.onDidDispose(() => { analysisPanel = undefined; }, null, []);
}

async function chooseAnalysisProvider() {
    const p = await activeProblem();
    if (!p) return;
    const title = path.basename(p.base);
    const choice = await vscode.window.showQuickPick(['Claude', 'Codex'], {
        placeHolder: `Analyze ${title} with…`,
        title: 'LeetCode Analysis Provider',
    });
    if (!choice) return;
    const provider = choice.toLowerCase();
    const report = reportPath(p.base, provider, p.folder);
    const fingerprint = fingerprintFor(p.base, provider);
    if (cachedAnalysis(report, fingerprint)) {
        showAnalysis(report, title, provider);
        vscode.window.showInformationMessage(`Opened cached ${choice} analysis; no tokens used.`);
        return;
    }

    const prompt = `Analyze this existing LeetCode solution using the leetcode-analysis skill.
Problem files:
- solution: ${p.base}.cpp
- statement: ${p.base}.md
- tests: ${p.base}.test.cpp

Analyze the complete hidden test suite for measured performance. Compare expected and actual asymptotic time and space complexity, use the benchmark output supplied by the runner for measured runtime and peak memory, and give only one or two concise optimization suggestions. Do not modify files and do not provide a full replacement solution.`;
    const tempDir = await fs.promises.mkdtemp(path.join(os.tmpdir(), 'leetcode-analysis-prompt-'));
    const promptFile = path.join(tempDir, 'prompt.txt');
    await fs.promises.writeFile(promptFile, prompt, 'utf8');
    await fs.promises.mkdir(path.dirname(report), { recursive: true });

    const terminal = vscode.window.createTerminal({ name: `LeetCode Analysis (${choice})`, cwd: p.folder.uri.fsPath });
    terminal.show(true);
    const command = ['bash', shellQuote(ANALYSIS_RUNNER), shellQuote(provider), shellQuote(p.base), shellQuote(report), shellQuote(fingerprint), shellQuote(promptFile)].join(' ');
    terminal.sendText(command, true);
    vscode.window.showInformationMessage(`${choice} analysis started in the integrated terminal.`);

    if (analysisPoll) clearInterval(analysisPoll);
    analysisPoll = setInterval(() => {
        if (cachedAnalysis(report, fingerprint)) {
            clearInterval(analysisPoll);
            analysisPoll = undefined;
            showAnalysis(report, title, provider);
            vscode.window.showInformationMessage(`Analysis saved to Questions/${reportTitle(p.base)}/analysis.${provider}.md`);
        }
    }, 1000);
    setTimeout(() => {
        if (analysisPoll) { clearInterval(analysisPoll); analysisPoll = undefined; }
    }, 15 * 60 * 1000);
}

async function askTestNumber(prompt) {
    return vscode.window.showInputBox({
        prompt,
        placeHolder: 'e.g. 3',
        validateInput: v => /^\d*$/.test(v.trim()) ? undefined : 'Enter a test number',
    });
}

async function run(testNumber) {
    const p = await activeProblem();
    if (!p) return;
    const env = testNumber ? { TEST: testNumber } : {};
    const exec = new vscode.ShellExecution(path.join(p.folder.uri.fsPath, 'run.sh'), [p.base + '.cpp'],
        { cwd: p.folder.uri.fsPath, env });
    const name = testNumber ? `run test #${testNumber}` : 'run all tests';
    const task = new vscode.Task({ type: 'shell', leetcode: name }, p.folder, name, 'LeetCode', exec, '$gcc');
    task.presentationOptions = { reveal: vscode.TaskRevealKind.Always, clear: true, panel: vscode.TaskPanelKind.Shared };
    vscode.tasks.executeTask(task);
}

async function runOne() {
    const n = await askTestNumber('Run which test?');
    if (n && n.trim()) run(n.trim());
}

async function debug() {
    const n = await askTestNumber('Debug which test? (leave empty for all)');
    if (n === undefined) return;
    const p = await activeProblem();
    if (!p) return;
    const env = n.trim() ? [`TEST=${n.trim()}`] : [];
    const ok = await vscode.debug.startDebugging(p.folder, {
        name: n.trim() ? `LeetCode: debug test #${n.trim()}` : 'LeetCode: debug all tests',
        type: 'lldb-dap',
        request: 'launch',
        program: path.join(BUILD_DIR, 'current'),
        cwd: BUILD_DIR,
        env,
        preLaunchTask: BUILD_TASK,
    });
    if (!ok) vscode.window.showErrorMessage('Could not start the debugger');
}

async function openSibling(suffix) {
    const editor = vscode.window.activeTextEditor;
    if (!editor) return;
    const file = problemBase(editor.document.uri) + suffix;
    if (!fs.existsSync(file)) return vscode.window.showWarningMessage(`${path.basename(file)} does not exist`);
    const uri = vscode.Uri.file(file);
    if (suffix === '.md') return vscode.commands.executeCommand('markdown.showPreviewToSide', uri);
    vscode.window.showTextDocument(uri, { viewColumn: vscode.ViewColumn.Beside });
}

function activate(context) {
    const items = [
        ['$(play) Run all tests', 'leetcode.runAll'],
        ['$(debug-step-into) Run test #', 'leetcode.runOne'],
        ['$(debug-alt) Debug', 'leetcode.debug'],
        ['$(beaker) Analyze', 'leetcode.analyze'],
    ].map(([text, command], i) => {
        const item = vscode.window.createStatusBarItem(vscode.StatusBarAlignment.Left, 100 - i);
        item.text = text;
        item.command = command;
        return item;
    });

    const refresh = () => {
        const p = vscode.window.activeTextEditor?.document.uri.fsPath ?? '';
        const show = /\.(cpp|md)$/.test(p) && p.includes('leetcode_cpp');
        for (const item of items) show ? item.show() : item.hide();
    };

    context.subscriptions.push(
        ...items,
        vscode.commands.registerCommand('leetcode.runAll', () => run()),
        vscode.commands.registerCommand('leetcode.runOne', runOne),
        vscode.commands.registerCommand('leetcode.debug', debug),
        vscode.commands.registerCommand('leetcode.analyze', chooseAnalysisProvider),
        vscode.commands.registerCommand('leetcode.openProblem', () => openSibling('.md')),
        vscode.commands.registerCommand('leetcode.openTests', () => openSibling('.test.cpp')),
        vscode.window.onDidChangeActiveTextEditor(refresh),
    );
    refresh();
}

module.exports = { activate, deactivate() {} };
