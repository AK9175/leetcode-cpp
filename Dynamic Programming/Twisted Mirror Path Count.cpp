class Solution {
public:
    long long row = 0, col = 0;
    long long MOD = 1000000007;
    //Go left = 1, Go Up = 2, Traverse until you find 0 on the grid, and return that cell value from the DP table
    //If you hit out of bounds return 0
    long long solve(long long i, long long j, vector<vector<long long>> &dp, vector<vector<int>>& grid, long long direction){
        while(i >= 0 && i < row && j >= 0 && j < col){
            if(direction == 1){
                j = j-1;
                direction = 2;
            }
            else{
                i = i-1;
                direction = 1;
            }
            if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 0) return dp[i][j];
        }
        return 0;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        row = grid.size(), col = grid[0].size();
        vector<vector<long long>> dp(row, vector<long long>(col , 0));
        for(long long i = 0 ; i < col ; i++){
            if(grid[0][i] == 0){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] = 1;
                break;
            }
        }

        for(long long i = 0 ; i < row ; i++){
            if(grid[i][0] == 0){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = 1;
                break;
            }
        }

        for(long long i = 1 ; i < row ; i++){
            for(long long j = 1 ; j < col ; j++){
                if (grid[i][j] == 1) continue;
                long long left = 0, right = 0;
                if(grid[i][j-1] == 0) left += dp[i][j-1];
                else left += solve(i,j,dp,grid,1); //Go left = 1, Go Up = 2
                if(grid[i-1][j] == 0) right += dp[i-1][j];
                else right += solve(i,j,dp,grid,2); //Go left = 1, Go Up = 2
                dp[i][j] = (left + right) % MOD;
            }
        }

        return dp[row-1][col-1];
    }
};
