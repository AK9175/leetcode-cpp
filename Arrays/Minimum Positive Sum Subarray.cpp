class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        while(l <= r){
            int sum = 0;
            for(int i = 0 ; i <= n - l ; i++){
                sum = prefix[i+l] - prefix[i];
                if(sum <= 0) continue;
                ans = min(sum, ans);
            }
            l++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
