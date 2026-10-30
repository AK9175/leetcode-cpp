class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<bool>>> dp(row, vector<vector<bool>>(col, vector<bool>(1024, false)));
        dp[0][0][grid[0][0]] = true;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                for(int k = 0 ; k < 1024 ; k++){
                    if(!dp[i][j][k]) continue;
                    if(j+1 < col){
                        dp[i][j+1][k ^ grid[i][j+1]] = true;
                    }
                    if(i+1 < row){
                        dp[i+1][j][k ^ grid[i+1][j]] = true;
                    }
                }
            }
        }

        for(int i = 0 ; i < 1024 ; i++){
            if(dp[row-1][col-1][i]) return i;
        }

        return -1;
    }
};
