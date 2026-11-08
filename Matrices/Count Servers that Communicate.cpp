class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), total = 0, notcommunicating = 0;
        vector<int> rowcount(row, 0);
        vector<int> columncount(col, 0);
        //Find total no of servers
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j]==1){
                    rowcount[i]++;
                    columncount[j]++;
                    total++;
                }
            }
        }

        //Find servers who can't communicate
        for(int i = 0 ; i < rowcount.size() ; i++){
            for(int j = 0 ; j < columncount.size() ; j++){
                if(rowcount[i] > 1) break;
                if(columncount[j] > 1) continue;
                if(grid[i][j] == 1) notcommunicating++;
            }
        }
        return total - notcommunicating;
    }
};

//  [[1,1,0,0], 2
                
//  [0,0,1,0], 1
               
//  [0,0,1,0], 1
               
//  [0,0,0,1]] 1
//   1 1 2 1      

  //total server - no of servers can't communicate 