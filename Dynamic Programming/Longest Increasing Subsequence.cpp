class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> temp;
        for(int i = 0 ; i < nums.size() ; i++){
            auto itr = lower_bound(temp.begin(), temp.end(), nums[i]);
            if(itr == temp.end()) temp.push_back(nums[i]);
            else *itr = nums[i];
            ans = max(ans, (int)temp.size());
        }

        return ans;
    }
};