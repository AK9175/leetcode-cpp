// 3934. Smallest Unique Subarray  [Hard]

class Solution {
public:

    bool hasUniqueSubarray(vector<int>& nums, int L) {
        const long long BASE = 100003;
        const long long MOD = 1000000007;

        int n = nums.size();
        long long highestPower = 1;

        for (int i = 1; i < L; i++) {
            highestPower = (highestPower * BASE) % MOD;
        }
        long long currentHash = 0;
        for (int i = 0; i < L; i++) {
            currentHash = (currentHash * BASE + nums[i]) % MOD;
        }
        unordered_map<long long, int> frequency;

        frequency[currentHash]++;

        for (int left = 1; left + L <= n; left++) {
            long long outgoing = nums[left - 1];
            long long incoming = nums[left + L - 1];
            currentHash = (currentHash - outgoing * highestPower) % MOD;
            if (currentHash < 0) {
                currentHash += MOD;
            }
            currentHash = (currentHash * BASE + incoming) % MOD;
            frequency[currentHash]++;
        }

        for (auto& [hash, count] : frequency) {
            if (count == 1) return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n, ans = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(hasUniqueSubarray(nums, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};