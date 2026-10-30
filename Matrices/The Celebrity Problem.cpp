// The Celebrity Problem  [Medium]

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int row = mat.size();
        int candidate = 0, cnt = 0, cnt2 = 0;
        if(row == 1) return 0;
        for(int i = 1 ; i < row ; i++){
            if(mat[candidate][i]){
                candidate = i;
            }
        }

        for(int j = 0 ; j < row ; j++){
            if(mat[candidate][j]) cnt++;
            if(mat[j][candidate]) cnt2++;
        }

        if(cnt == 1 && cnt2 == row) return candidate;
        return -1;
    }
};

// 1 0 1 0 0
// 0 1 1 0 0
// 0 0 1 0 0
// 0 0 1 1 0
// 0 0 1 0 1

// {1, 1, 0}, 
// {0, 1, 0}, 
// {0, 1, 1}

// 1 0
// 0 1