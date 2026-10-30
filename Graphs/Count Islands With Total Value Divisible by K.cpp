class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &grid, int row, int col, long long &val){
        if(!(i >= 0 && i < row && j >= 0 && j < col) || (grid[i][j] == 0)) return;
        val += grid[i][j];
        grid[i][j] = 0;
        dfs(i, j+1, grid, row, col, val);
        dfs(i+1, j, grid, row, col, val);
        dfs(i-1, j, grid, row, col, val);
        dfs(i, j-1, grid, row, col, val);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] != 0){
                    long long val = 0;
                    dfs(i, j, grid, row, col, val);
                    if(val % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};
