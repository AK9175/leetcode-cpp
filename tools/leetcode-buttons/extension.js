// Editor-title and status-bar buttons for the local LeetCode C++ workspace.
// A problem is X.cpp (solution), X.md (description) and X.test.cpp (tests);
// every button works from any of the three.
const vscode = require('vscode');
const path = require('path');
const fs = require('fs');

const BUILD_TASK = 'LeetCode: build active file';
const BUILD_DIR = path.join(require('os').homedir(), 'Library/Caches/leetcode_cpp');

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
        vscode.commands.registerCommand('leetcode.openProblem', () => openSibling('.md')),
        vscode.commands.registerCommand('leetcode.openTests', () => openSibling('.test.cpp')),
        vscode.window.onDidChangeActiveTextEditor(refresh),
    );
    refresh();
}

module.exports = { activate, deactivate() {} };
