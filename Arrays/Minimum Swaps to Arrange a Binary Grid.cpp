class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> actual;
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            int count = 0;
            for(int j = grid[i].size() - 1 ; j >= 0 ; j--){
                if(grid[i][j] == 0){
                    count++;
                }
                else{
                    break;
                }
            }
            actual.push_back(count);
        }

        vector<int> needed = actual;
        sort(needed.begin(), needed.end(), greater<int>());
    }
};
