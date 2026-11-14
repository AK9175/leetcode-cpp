class Solution {
public:
    //using the theory of exactly(k) = atmost(k) - atmost(k-1)
    //Applying Sliding window
    int atmost(int k, vector<int> &nums){
        int unique = 0, totalAtmostK = 0;
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, right = 0;
        while(right < n){
            freq[nums[right]]++;
            if(freq[nums[right]] == 1) unique++;
            if(unique <= k)totalAtmostK += right - left + 1;
            while(unique > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) unique--;
                if(unique <= k)totalAtmostK += right - left;
                left++;
            }
            right++;
        }
        return totalAtmostK;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(k, nums) - atmost(k-1, nums);
    }
};

//We somehow efficiently need to find no of unique elements in the range (l, r)
//if k = 3 is given that means we need to search subarrays whose length is >= k
//because in a window < k there wont be suffiecient elements in the window to calculate  
//when subarrays and k is mentioned we have to apply exactly(k) = atmost(k) - atmost(k-1)

// [1, 1, 2, 2, 3, 3] k = 2
    // [1,1,2,2]
// [1] => 1
// [1] => 1
// [2] => 1
// [2] => 1
// [3] => 1
// [3] => 1
// [1,1] => 1
// [1,2] => 2
// [2,2] => 1
// [1,1,2] => 2
// [1,2,2]=> 2
//[1,1,2,2] => 2
// [2,2,3] => 2
// [2,3] => 2
// [2,3,3] => 2
// [2,2,3,3] => 2
// [3,3] => 2
//Total count = 10
//n*(n+1)/2 -> 4*5/2 => 10
// when ever we find that we have found a subarray which exactly has k unique 
//that means all subarays in that subarray are atmost(k) 
//we can do n*(n+1)/2, but for each interval we have to find number of elements common in old and new intervals and subtract 
// the m*m+1/2 of common elements

//Happy Sliding ;)