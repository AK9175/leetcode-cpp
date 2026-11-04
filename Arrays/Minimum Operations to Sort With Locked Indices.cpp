class Solution {
public:
    vector<vector<int>> intervals;
    
    void findIntervalsInCycles(vector<int>& nums){
        int right = 0, left = 0, n = nums.size(), i = left;
        vector<int> visited(n, 0);
        while(i < n){
            if(i+1 == nums[i] || visited[i]){
                if(intervals.empty()) intervals.push_back({left, right});
                else{
                    if(left > intervals.back()[1]){
                        intervals.push_back({left, right});
                    }
                    else{
                        intervals.back()[0] = min(left, intervals.back()[0]);
                        intervals.back()[1] = max(right, intervals.back()[1]);
                    }
                }
                left = i+1;
                right = left;
                i = left;
            }
            else{
                visited[i] = 1;
                i = nums[i]-1;
                right = max(right, i);
            }
        }
        
    }

    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int ans = 0, n = nums.size();
        //Find all the intervals, and you need all the values to be unlocked in that interval, except the one where the left and right of the interval is same
        //Because we have to apply bubble sort in the interval to figure out how many adh=jecent swaps are needed to make the array sorted
        findIntervalsInCycles(nums);
        
        for(int i = 0 ; i < intervals.size() ; i++){
            if(intervals[i][0] == intervals[i][1]) continue;
            for(int j = intervals[i][0] ; j <= intervals[i][1] ; j++){
                if(locked[j] == 1) ans++;
            }
        }

        if(ans <= k){
            for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
                for (int j = 0; j < n - i - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        swap(nums[j], nums[j + 1]);
                        ans++;
                        swapped = true;
                    }
                }
            if (!swapped) {
                break;
            }
    }       return ans;
        }
        return -1;
    }
};
