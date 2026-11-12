class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incMax = 1, decMax = 1;
        int incCount = 1, decCount = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > nums[i-1]){
                decCount = 1;
                incCount++;
                incMax = max(incMax, incCount);
                decMax = max(decMax, decCount);
            }
            else if(nums[i] < nums[i-1]){
                incCount = 1;
                decCount++;
                incMax = max(incMax, incCount);
                decMax = max(decMax, decCount);
            }
            else{
                decCount = 1;
                incCount = 1;
                incMax = max(incMax, incCount);
                decMax = max(decMax, decCount);
            }
        }

        return max(incMax, decMax);
    }
};
