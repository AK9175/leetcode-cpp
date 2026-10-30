class Solution {
public:
    bool canPartitionAfterRemoval(vector<int>& nums) {
        long long n = nums.size(), sum = 0;
        long long even = 0; // this means we have to subtract a odd number'
        unordered_map<long long, long long> pre;
        unordered_map<long long, long long> post;
        for(long long i = 0 ; i < n ; i++){
            sum += nums[i];
            if(!pre.count(sum)) pre[sum] = i;
        }
        sum = 0;
        for(long long i = n-1 ; i >= 0 ; i--){
            sum += nums[i];
            if(!post.count(sum)) post[sum] = i;
        }

        if(sum%2==0) even = 1;

        if(even){
            if(nums[0]%2 == 0){
                long long tofind = (sum-nums[0])/2;
                if(post.count(tofind) && post[tofind] > 1) return true;
            }
            if(nums[n-1]%2 == 0){
                long long tofind = (sum-nums[n-1])/2;
                if(pre.count(tofind) && pre[tofind] < n-2) return true;
            }
            for(long long i = 1 ; i < n-1 ; i++){
                if(nums[i]%2 == 0){
                    long long tofind = (sum-nums[i])/2;
                    if(pre.count(tofind) && pre[tofind] < i) return true;
                    if(post.count(tofind) && post[tofind] > i) return true;
                }
            }
        }
        else{
            if(nums[0]%2 != 0){
                long long tofind = (sum-nums[0])/2;
                if(post.count(tofind)  && post[tofind] > 1) return true;
            }
            if(nums[n-1]%2 != 0){
                long long tofind = (sum-nums[n-1])/2;
                if(pre.count(tofind) && pre[tofind] < n-2) return true;
            }
            for(long long i = 1 ; i < n-1 ; i++){
                if(nums[i]%2 != 0){
                    long long tofind = (sum-nums[i])/2;
                    if(pre.count(tofind) && pre[tofind] < i) return true;
                    if(post.count(tofind) && post[tofind] > i) return true;
                }
            }
        }

        return false;
    }
};
