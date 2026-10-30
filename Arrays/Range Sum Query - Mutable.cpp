class NumArray {
public:
    vector<int> BIT;
    vector<int> nums;
    int n;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        BIT.assign(n+1, 0);

        for(int i = 1 ; i <= n ; i++){
            int val = nums[i-1]; 
            int index = i;
            while(index <= n){
                BIT[index] += val;
                index += index & -index;
            }
        }
    }
    
    void update(int index, int val) {
        index++;
        int diff = val - nums[index-1];
        nums[index - 1] = val;
        while(index <= n){
            BIT[index] += diff;
            index += index & -index;
        }
    }

    int query(int index){
        int sum = 0;
        while(index > 0){
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        int rightSum = query(right + 1);
        int leftSum = query(left);
        return rightSum - leftSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */