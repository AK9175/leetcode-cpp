class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || (n == 2 && nums[0] < nums[1])) return 0;
        else if(n == 2) return 1; 
        int zero = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                zero = i;
                break;
            }
        }

        if(zero != 0 && zero != n-1){
            if(nums[zero+1] == 1){                     
                for(int t = 0 ; t < n ; t++){
                    if(nums[(zero + t) % n] != t) return -1;
                }
                return min(zero, 2 + (n - zero));
            }
            else if(nums[zero-1] == 1){                 
                for(int t = 0 ; t < n ; t++){
                    if(nums[(zero - t + n) % n] != t) return -1;
                }
                return min(1 + (n - 1 - zero), zero + 2);
            }
            else return -1;
        }
        else if(zero == 0){
            if(nums[zero+1] == 1){
                for(int i = 0 ; i < n-1 ; i++){
                    if(nums[i]+1 != nums[i+1]) return -1;
                }
                return 0;
            }
            else if(nums[n-1] == 1){
                for(int i = n-1 ; i >= 1 ; i--){
                    if(nums[i] != nums[(i+1)%n]+1){
                        return -1;
                    }
                }
                return 2;
            }
            else return -1;
        }
        else{
            if(nums[zero-1] == 1){
                for(int i = n-1 ; i >= 1 ; i--){
                    if(nums[i-1] != nums[i]+1){
                        return -1;
                    }
                }
                return 1;
            }
            else if(nums[0] == 1){
                for(int i = 0 ; i < n-2 ; i++){
                    if(nums[i]+1 != nums[i+1]){
                        return -1;
                    }
                }
                return min(n-1, 3);
            }
        }

        return -1;
        
    }
};

// 0,1,2,3,4
// 0,4,3,2,1

// 1,2,3,4,0
// 4,3,2,1,0

// [1,2,3,4,5,0]
//   reverse      →  [0,5,4,3,2,1]
//   rotate left  →  [5,4,3,2,1,0]
//   reverse      →  [0,1,2,3,4]


// 4,3,2,1,0,5
// 5,0,1,2,3,4
// 0,1,2,3,4,5

// [2,3,4,0,1]
//  1,0,4,3,2
//  0,4,3,2,1
//  4,3,2,1,0
//. 0,1,2,3,4

// 2,3,4,5,6,0,1
// 1,0,6,5,4,3,2
// 0,6,5,4,3,2,1
// 6,5,4,3,2,1,0
// 01,2,3,4,5,6