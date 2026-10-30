class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> freq;
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int tofind = arr[i] - difference;
            if(freq[tofind] == 0){
                if(freq[arr[i]] == 0){
                    freq[arr[i]] = 1;
                }
            }
            else{
                freq[arr[i]] = freq[tofind]+1;
            }

            ans = max(ans, freq[arr[i]]);
        }

        return ans;
    }
};

// if difference is > 0, then we have to find subsequence which is increasing
// if difference is < 0 then we have to find subsequence which is decresing
// if differnce s = 0 then we have to find subsequence which is constant number throughout
// Use Hash map to figure out longest subsequence ending at that index which staisfies the criteria of difference.
// 1 
// 5 3 1
// 7 5 3 1
// 8
// Size Map
// 1 : 4
// 5 : 2
// 7 : 1
// 8 : 1
// 3 : 3
// 4 : 2