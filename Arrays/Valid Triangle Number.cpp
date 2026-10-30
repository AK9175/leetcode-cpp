class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int total = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                int tofind = nums[i] + nums[j];
                int k = -1;
                auto itr = upper_bound(nums.begin(), nums.end(), tofind-1);
                if(itr == nums.end()) k = nums.size()-1;
                else k = itr - nums.begin();
                total += k - j;
            }
        }

        return total;
    }
};