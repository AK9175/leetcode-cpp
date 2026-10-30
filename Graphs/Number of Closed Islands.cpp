class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &grid, int row, int col){
        if(!(i >= 0 && i < row && j >= 0 && j < col) || grid[i][j] == 1) return;
        grid[i][j] = 1;
        dfs(i+1, j, grid, row, col);
        dfs(i, j+1, grid, row, col);
        dfs(i-1, j, grid, row, col);
        dfs(i, j-1, grid, row, col);
    }

    void floodfill(int i, int j, vector<vector<int>> &grid, int row, int col){
        if(!(i >= 0 && i < row && j >= 0 && j < col) || grid[i][j] == 2 || grid[i][j] == 1) return;
        grid[i][j] = 2;
        dfs(i+1, j, grid, row, col);
        dfs(i, j+1, grid, row, col);
        dfs(i-1, j, grid, row, col);
        dfs(i, j-1, grid, row, col);
    }

    int closedIsland(vector<vector<int>>& grid) {
        //Converting all Islands to water which are close to the border islands
        //Because the land is connected to the border there is no use counting that piece of land as island
        int row = grid.size(), col = grid[0].size(), ans = 0;
        //Upper and down row
        for(int i = 0 ; i < col ; i++){
            if(grid[0][i] == 0){
                dfs(0, i, grid, row, col);
            }
            if(grid[row-1][i] == 0) {
                dfs(row-1, i, grid, row, col);
            }
        }
        //Left and right column
        for(int i = 0 ; i < row ; i++){
            if(grid[i][0] == 0) {
                dfs(i, 0, grid, row, col);
            }
            if(grid[i][col-1] == 0) {
                dfs(i, col-1, grid, row, col);
            }
        }
        //Now normal floodfill (dfs) in the internal grid looking for 0's 
        //and marking them visited, and after each dfs completion, incrementing the ans
        
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j]==0){
                    floodfill(i, j, grid, row, col);
                    ans++;
                }
            }
        }

        return ans;

    }
};


// 0 1 0
// 1 0 1
// 0 1 0

//1 1 1 1 1 1 1
//1 0 0 0 0 0 1
//1 0 1 1 1 0 1
//1 0 1 0 1 0 1
//1 0 1 1 1 0 1
//1 0 0 0 0 0 1
//1 1 1 1 1 1 1