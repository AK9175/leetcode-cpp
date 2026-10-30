class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN, sum = 0;
        unordered_map<int, long long> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(i == 0){
                mp[nums[i]] = 0;
                continue;
            }
            int tofind1 = k + nums[i];
            int tofind2 = nums[i] - k;
            if(mp.count(tofind1)){
                ans = max(ans, (long long)sum - mp[tofind1]);
            }
            if(mp.count(tofind2)){
                ans = max(ans, (long long)sum - mp[tofind2]);
            }

            if(mp.count(nums[i])){
                mp[nums[i]] = min(mp[nums[i]], sum - nums[i]);
            }
            else {
                mp[nums[i]] = sum - nums[i];
            }
        }

        if(ans == LLONG_MIN) return 0;
        return ans;
    }
};