class Solution {
public:

    vector<string> ans;

    void solve(int opencnt, int closecnt, int &n, string curr){
        if(opencnt > n || closecnt > opencnt) return;
        if(opencnt == n && closecnt == n) {
            ans.push_back(curr);
            return;
        }
        solve(opencnt+1, closecnt, n, curr+"(");
        solve(opencnt, closecnt+1, n, curr+")");
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(0, 0, n, curr);
        return ans;
    }
};