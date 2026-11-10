// 3693. Climbing Stairs II  [Medium]
// Top-down recursion + memoization variant.
// NOTE: recurses to depth n, so it can stack-overflow around n = 1e5 under a small
// stack (the local sanitized build does). The iterative version in
// "Climbing Stairs II.cpp" avoids that. Kept here as the original top-down approach.

class Solution {
public:
    int solve(int ind, vector<int>& costs, vector<int>& dp, int n){
        if(ind > n) return INT_MAX;
        if(ind == n) return 0;
        if(dp[ind] != INT_MAX) return dp[ind];
        //For current player, it will take left and rest of the array will be sent to other
        int ostep = solve(ind+1, costs, dp, n);
        if(ostep != INT_MAX) ostep += costs[ind] + 1;

        int tstep = solve(ind+2, costs, dp, n);
        if(tstep != INT_MAX) tstep += costs[ind+1] + 4;

        int thstep = solve(ind+3, costs, dp, n);
        if(thstep != INT_MAX) thstep += costs[ind+2] + 9;

        dp[ind] = min({ostep, tstep, thstep});
        return dp[ind];
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n, INT_MAX);
        return solve(0, costs, dp, n);
    }
};
