// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum  [Medium]

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = (int)arr.size();
        int ans = INT_MAX, cnt = 0;
        vector<int> dp(n, INT_MAX);
        map<int, int> prefix;
        for(int i = 0 ; i < n ; i++){
            cnt += arr[i];
            prefix[cnt] = i;
        }
        
        for(auto it : prefix){
            int i = it.second;
            int currVal = it.first;
            int toFind = currVal - target;
            if(toFind < 0) continue;
            if(toFind == 0){
                dp[i] = i+1;
                continue;
            }
            else if(prefix.find(toFind) != prefix.end()){
                if(dp[prefix[toFind]] == INT_MAX){
                    dp[i] = min(i - prefix[toFind], dp[i-1]);
                }
                else{
                    ans = min(ans, dp[prefix[toFind]] + i - prefix[toFind]);
                    dp[i] = min(dp[prefix[toFind]], i - prefix[toFind]);
                }
            }
            else if(i-1 >= 0) dp[i] = dp[i-1];
            else return -1;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

// nums = [1,1,1,2,1,1,1]
// target = 3
// 0 1 2 3 4 5 6
// 1 2 3 5 6 7 8 (prefix)
//      dp
// m m 3 2 