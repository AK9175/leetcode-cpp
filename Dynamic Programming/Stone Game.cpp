class Solution {
public:

    int solve(int left, int right, vector<vector<int>> &dp, vector<int>& piles){
        if(left == right) return piles[left];
        if(dp[left][right] != INT_MIN) return dp[left][right];
        //For current player, it will take left and rest of the array will be sent to other
        //player to play their optimal move
        //so solves denotes that a player optimally taking so they can win
        //for eg [5,3]
        //for 1st player, if that player takes left one that is 5
        // so 5 - solve(1,1,dp,piles) => 5 - 3 = 2, so if 1st player takes 5 he'll profit 2
        // and 3 - solve(0,0,dp,piles) => 3 - 5 = -2 so if 1st player takes 3 he'll lose 2
        int takeLeft = piles[left] - solve(left+1, right, dp, piles);
        int takeright = piles[right] - solve(left, right-1, dp, piles);
        //max(2,-2)
        dp[left][right] = max(takeLeft, takeright);
        return dp[left][right]; // return 2
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int aliceAdvantage = solve(0, n-1, dp, piles);
        //and if alice is playing 1st if maximum advantage she can make is below 0
        //that means the other player has +ve advantage
        if(aliceAdvantage > 0) return true;
        return false;
    }
};
