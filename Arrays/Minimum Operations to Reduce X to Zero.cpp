class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            total += nums[i];
        }

        int tofind = total - x, maxi = INT_MIN;
        int left = 0, right = 0, sum = 0;

        while(right <= nums.size()){
            if(sum == tofind){
                maxi = max(maxi, right-left);
                sum -= nums[left++];
            }
            else if(sum < tofind){
                sum += nums[right++];
            }
            else if(left < right && sum > tofind){
                sum -= nums[left++];
            }
            else{
                right++;
                left++;
            }
        }
        if(sum == tofind){
            maxi = max(maxi, right-left);
        }
        if(maxi == INT_MIN) return -1;
        return nums.size() - maxi;
    }
};

// [1,10,1,3,4] value of x is 11