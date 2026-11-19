class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size(), currmin = 0, currmax = 0, ans = INT_MAX;
        sort(nums.begin(), nums.end());

        int median = 0, ind = n/2, count = 2;
        if(n%2 == 0) median = (nums[ind-1] + nums[ind])/2;
        else median = nums[ind];
        int i = 0;
        while(i < n && count){
            if(i < n && nums[i] != median) count--;
            i++;
        }
        if(i < n-1){
            currmin = nums[i];
            ans = min(ans, nums[n-1] - currmin);
        }
        else if(i == n-1){
            currmin = median;
            ans = min(ans, nums[n-1] - currmin);
        }
        else ans = 0;

        count = 2;
        i = n-1;
        while(i >= 0 && count){
            if(i >= 0 && nums[i] != median) count--;
            i--;
        }

        if(i > 0){
            currmax = nums[i];
            ans = min(ans, currmax - nums[0]);
        }
        else if(i == 0){
            currmax = median;
            ans = min(ans, currmax - nums[0]);
        }
        else ans = 0;

        ans = min(ans, nums[n-2] - nums[1]);
        

        return  ans;
    }
};