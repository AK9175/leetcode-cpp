// 2267. Check if There Is a Valid Parentheses String Path  [Hard]

class Solution {
public:

    bool solve(int i, int j, vector<vector<char>>& grid, int &row, int &col, vector<vector<vector<int>>> &dp, int balance){
        if(i >= row || j >= col) return false;

        if(grid[i][j] == '(') balance++;
        else balance--;

        if(balance < 0) return false;
        if(i == row-1 && j == col-1 && balance == 0) return true;

        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        return dp[i][j][balance] = solve(i+1, j, grid, row, col, dp, balance) || solve(i, j+1, grid, row, col, dp, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(row+col, -1)));
        if(grid[0][0] != '(' || grid[row-1][col-1] != ')') return false;
        if(solve(0,0, grid, row, col, dp, 0)) return true;
        return false;
    }
};
