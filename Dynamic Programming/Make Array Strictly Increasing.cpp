// 1187. Make Array Strictly Increasing  [Hard]

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> dp;
        sort(arr2.begin(), arr2.end());
        int ans = INT_MAX;

        dp[arr1[0]] = 0;
        auto itr = upper_bound(arr2.begin(), arr2.end(), -1);
        if(itr != arr2.end()){
            if(dp.find(*itr) == dp.end()) dp[*itr] = 1;
        }
        for(int i = 1 ; i < arr1.size() ; i++){
            int currNonReplacedValue = arr1[i];
            map<int, int> currdp;
            for(auto itr : dp){
                auto currReplacedValueitr = upper_bound(arr2.begin(), arr2.end(), itr.first);
                int prevValue = itr.first;
                if(prevValue < currNonReplacedValue){
                    if(currdp.find(currNonReplacedValue) != currdp.end()){
                        currdp[currNonReplacedValue] = min(currdp[currNonReplacedValue], dp[prevValue]);
                    }
                    else currdp[currNonReplacedValue] = dp[prevValue];
                }
                if(currReplacedValueitr != arr2.end()){
                    if(currdp.find(*currReplacedValueitr) != currdp.end()){
                        currdp[*currReplacedValueitr] = min(currdp[*currReplacedValueitr], dp[prevValue] + 1);
                    }
                    else currdp[*currReplacedValueitr] =  dp[prevValue] + 1;
                }
            }
            dp = currdp;
        }

        for(auto itr : dp){
            ans = min(itr.second, ans);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};