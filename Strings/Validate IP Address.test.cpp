// Hidden judge for "Validate IP Address.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Validate IP Address.cpp"

// Runs a family of strings that must all produce the same verdict.
static CheckResult allGive(const vector<string>& inputs, const string& verdict) {
    vector<string> got;
    for (const string& queryIP : inputs) got.push_back(Solution().validIPAddress(queryIP));
    return expectEq(got, vector<string>(inputs.size(), verdict));
}

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        string queryIP = "172.16.254.1";
        return expectEq(Solution().validIPAddress(queryIP), "IPv4");
    });

    T.test("Example 2", [] {
        string queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
        return expectEq(Solution().validIPAddress(queryIP), "IPv6");
    });

    T.test("Example 3", [] {
        string queryIP = "256.256.256.256";
        return expectEq(Solution().validIPAddress(queryIP), "Neither");
    });

    T.test("IPv4, all parts zero", [] {
        string queryIP = "0.0.0.0";
        return expectEq(Solution().validIPAddress(queryIP), "IPv4");
    });

    T.test("IPv4, all parts at the maximum", [] {
        string queryIP = "255.255.255.255";
        return expectEq(Solution().validIPAddress(queryIP), "IPv4");
    });

    T.test("IPv4 with leading zeros", [] {
        vector<string> inputs = {"192.168.01.1", "192.168.1.00", "01.1.1.1", "0.00.0.0"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv4 with the wrong number of parts or empty parts", [] {
        vector<string> inputs = {"1.1.1", "1.1.1.1.1", "1.1.1.", ".1.1.1", "1..1.1", "1.1..1"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv4 parts out of range", [] {
        vector<string> inputs = {"256.1.1.1", "1.1.1.256", "999.1.1.1", "1.1.1.1000"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv4 with letters in a part", [] {
        vector<string> inputs = {"1e1.4.5.6", "12.34.56.oops", "a.b.c.d"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv6, every group at the maximum", [] {
        string queryIP = "FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF:FFFF";
        return expectEq(Solution().validIPAddress(queryIP), "IPv6");
    });

    T.test("IPv6, every group a single digit", [] {
        string queryIP = "1:2:3:4:5:6:7:8";
        return expectEq(Solution().validIPAddress(queryIP), "IPv6");
    });

    T.test("IPv6, every group zero", [] {
        string queryIP = "0:0:0:0:0:0:0:0";
        return expectEq(Solution().validIPAddress(queryIP), "IPv6");
    });

    T.test("IPv6 group longer than four characters", [] {
        vector<string> inputs = {"02001:0db8:85a3:0000:0000:8a2e:0370:7334",
                                 "2001:0db8:85a3:0:0:8A2E:0370:73345"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv6 with empty groups or shorthand notation", [] {
        vector<string> inputs = {"2001:0db8:85a3::8A2E:0370:7334", "::", "1::8",
                                 ":1:2:3:4:5:6:7", "1:2:3:4:5:6:7:"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv6 with non-hexadecimal letters", [] {
        vector<string> inputs = {"20EE:FGb8:85a3:0:0:8A2E:0370:7334",
                                 "2001:0db8:85a3:0:0:8A2E:037j:7334"};
        return allGive(inputs, "Neither");
    });

    T.test("IPv6 with the wrong number of groups", [] {
        vector<string> inputs = {"1:2:3:4:5:6:7", "1:2:3:4:5:6:7:8:9"};
        return allGive(inputs, "Neither");
    });

    T.test("both separators mixed together", [] {
        vector<string> inputs = {"1.1.1.1:2", "1:2:3:4:5:6:7:8.9", "1:2:3:4:5:6:7:8:"};
        return allGive(inputs, "Neither");
    });

    T.test("degenerate strings", [] {
        vector<string> inputs = {"", "1", ".", ":", "...", ":::::::"};
        return allGive(inputs, "Neither");
    });

    T.test("very long inputs (timing check)", [] {
        string dotted;
        for (int i = 0; i < 50000; ++i) dotted += "1.";
        string digits(100000, '7');
        vector<string> inputs = {dotted, digits};
        return allGive(inputs, "Neither");
    });

    return T.summary();
}
