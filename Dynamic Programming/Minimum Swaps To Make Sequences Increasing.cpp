class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), minNoSwaps = -1, minSwaps = -1;
        int prevMinNoSwaps = 0, prevMinSwaps = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i] && nums2[i-1] < nums1[i] && nums1[i-1] < nums2[i]){
                minNoSwaps = min(prevMinNoSwaps, prevMinSwaps);
            }
            else if(nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]){
                minNoSwaps = prevMinNoSwaps;
            }
            else if(nums2[i-1] < nums1[i] && nums1[i-1] < nums2[i]){
                minNoSwaps = prevMinSwaps;
            }
            if(nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i] && nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]){
                minSwaps = min(prevMinNoSwaps + 1, prevMinSwaps + 1);
            }
            else if(nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]){
                minSwaps = prevMinNoSwaps + 1;
            }
            else if(nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]){
                minSwaps = prevMinSwaps + 1;
            }
            prevMinNoSwaps = minNoSwaps;
            prevMinSwaps = minSwaps;
        }

        return min(minSwaps, minNoSwaps);
    }
};
