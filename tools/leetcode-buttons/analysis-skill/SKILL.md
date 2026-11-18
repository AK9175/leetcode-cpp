---
name: leetcode-analysis
description: Analyze an existing LeetCode C++ solution against its problem statement and tests, reporting expected versus actual time and space complexity, measured runtime and peak memory when supplied, correctness concerns, and one or two concise optimization suggestions. Use when reviewing a completed or attempted solution; do not modify the user's files or reveal a full replacement solution unless explicitly requested.
---

# LeetCode solution analysis

Analyze the active problem using the solution `.cpp`, problem `.md`, hidden tests `.test.cpp`, and benchmark output supplied in the request.

Do not edit, rewrite, or format any repository file. Do not provide a full replacement implementation unless the user explicitly asks for one.

## Formatting rules

The report is shown in a lightweight Markdown viewer that does **not** render LaTeX. Write plain GitHub-flavored Markdown only.

- Do not use LaTeX or math delimiters: no `\(...\)`, `\[...\]`, `\left`, `\right`, `\sum`, `\Theta`, `\tau`, `\log`, `\,`, `\cdot`, etc.
- Write complexity in plain ASCII: `O(n^3 log n + k*n^2)`, `O(n^2)`, `k <= n/2`. Use `^` for exponents and `*` for multiplication.
- Summations and similar may be written in words (e.g. "sum over L from 2 to n of ...") or left out; keep it readable as plain text.
- Keep math inside backticks when it helps, e.g. `` `O(n^2)` ``.

Return concise Markdown with these sections:

## Complexity

- Expected optimal time complexity from the constraints.
- Actual time complexity of the submitted implementation, including the dominant operations and any worst-case behavior.
- Expected optimal auxiliary space complexity.
- Actual auxiliary space complexity of the submitted implementation.

## Measured performance

Report runtime and peak memory only from the supplied `-O2` benchmark output. Clearly label measurements as local and distinguish them from asymptotic complexity. If compilation or execution failed, say so instead of inventing numbers.

## Correctness

State whether the implementation appears correct for the stated contract and tests. Mention concrete edge cases, overflow risks, mutation behavior, or undefined behavior when relevant.

## Suggestions

Give one or two short, actionable suggestions for reaching the expected time or space complexity. Do not disclose a complete solution or detailed algorithm walkthrough unless asked.

Keep the explanation specific to the submitted code. Do not claim that a benchmark proves asymptotic complexity.
