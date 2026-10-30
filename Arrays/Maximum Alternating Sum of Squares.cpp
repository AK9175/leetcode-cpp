class Solution {
public:

    void quickselect(int left, int right, vector<int> &nums, int k){
        if (left >= right)
            return;
        int pivotIndex = right;
        int index = left;

        for(int i = left ; i < pivotIndex ; i++){
            if(nums[i] >= nums[pivotIndex]){
                swap(nums[index], nums[i]);
                index++;
            }
        }

        swap(nums[index], nums[pivotIndex]);

        if(k == index) return;
        if(k < index){
            quickselect(left, index-1, nums, k);
        }
        else quickselect(index+1, right, nums, k);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int k = 0, n = nums.size(); 
        long long pos = 0, neg = 0;
        if(nums.size()==1) return nums[0]*nums[0];
        k = n - n/2;
        for(int i = 0 ; i < nums.size() ; i++){
            nums[i] = 1LL * nums[i] * nums[i];
        }
        quickselect(0, n-1, nums, k);

        for(int i = 0 ; i < n ; i++){
            if(i < k) pos += nums[i];
            else neg += nums[i];
        }

        return pos-neg;
    }
};

