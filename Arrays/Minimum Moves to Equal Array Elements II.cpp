class Solution {
public:

    int quickselect(vector<int>& nums, int low, int high){
        int left = low, pivot = nums[high];
        for(int right = left ; right < high ; right++){
            if(nums[right] < pivot){
                swap(nums[left], nums[right]);
                left++;
            }
        }
        swap(nums[left], nums[high]);

        return left;
    }

    int solve(int targetIndex, vector<int> &nums){
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int ind = quickselect(nums, left, right);
            if(ind == targetIndex) return nums[ind];
            else if(ind < targetIndex){
                left = ind + 1;
            }
            else right = ind - 1;
        }
    }



    int minMoves2(vector<int>& nums) {
        int  sum = 0, ans = 0, n = nums.size(), i = n-1;
        if(n == 1) return 0;
        double median;

        if (n % 2 == 1) {
            median = solve(n / 2, nums);
        } else {
            median = (solve(n / 2 - 1, nums) + solve(n / 2, nums)) / 2.0;
        }
        int roundedMedian = round(median);
        for(int i = 0 ; i < nums.size() ; i++){
            ans += abs(nums[i] - roundedMedian);
        }

        return ans;
    }
};
