class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> diff(nums1.size(), 0);
        long long ans = 0;
        for(int i = 0 ; i < nums1.size() ; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        sort(diff.begin(), diff.end(), greater<int>());

        int count = k1+k2;

        

        return ans;
    }
};
