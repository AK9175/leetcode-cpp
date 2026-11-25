class Solution {
public:
    //Sliding window maxinggg
    int maxLength(vector<int>& nums) {
        int left = 0, right = 1, n = nums.size(), ans = -1;
        long long productinrange = 1;
        //product in range will be denoted by productinrange, and product lehind left pointer will be repr by productbehindleft
        //these two will help in sliding window and help prevent recalculating the product for each subarray
        productinrange = nums[left];
        long long currgcd = gcd(nums[0], 0);
        long long currlcm = lcm(nums[0], 1);
        while(left < right && right < n){
            currgcd = gcd(currgcd, nums[right]);
            currlcm = lcm(currlcm, nums[right]);
            productinrange *= nums[right];
            while(productinrange != currgcd * currlcm && left <= right - 1){
                productinrange = productinrange/nums[left];
                left++;
                currgcd = 0, currlcm = 1;
                for(int i = left ; i <= right ; i++){
                    currgcd = gcd(currgcd, nums[i]);
                    currlcm = lcm(currlcm, nums[i]);
                }
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
