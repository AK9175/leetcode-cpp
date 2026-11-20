// 3041. Maximize Consecutive Elements in an Array After Modification  [Hard]

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dp0 = 1, dp1 = 1, ans = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i-1] + 1 == nums[i]){
                dp0++;
                dp1++;
            }
            else if(nums[i-1] == nums[i]){
                dp1 = dp0 + 1;
            }
            else if(nums[i-1] + 2 == nums[i]){
                dp0 = dp1 + 1;
                dp1 = 1;
            }
            else {
                dp0 = 1, dp1 = 1;
            }
            ans = max({ans, dp0, dp1});
        } 

        return ans;
    }
};
