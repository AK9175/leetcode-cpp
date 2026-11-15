class Solution {
public:
    long long MOD = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n, 0);
        vector<int> odd(n, 0), even(n, 0);
        int evenCnt = 0, oddCnt = 0;
        int ans = 0;
        if(arr[0]%2 == 1){
            ans++;
            oddCnt++;
        }
        else {
            evenCnt++;
        }
        prefix[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = arr[i] + prefix[i-1];
            if(prefix[i]%2 == 1){
                oddCnt++;
                odd[i] = oddCnt;
                even[i] = evenCnt;
                ans = (ans + (even[i]+1) % MOD) % MOD;
            }
            else{
                evenCnt++;
                even[i] = evenCnt;
                odd[i] = oddCnt;
                ans = (ans + odd[i]) % MOD;
            }
        }

        return ans % MOD;
    }
};
//Prefix sum of 3rd example
//[1,2,3,4,5,6,7]
// 1,3,6,10,15,21,28
// 0,1,2, 2, 2, 3, 4 => oddCount
// 0,0,0, 1, 2, 2, 2 => evenCount
// so here odd number needs even number which can do (odd - even) => odd
// so here even number needs odd number which can do (even - odd) => odd

// basically if we are at for example we are at 15(all subarrays ending at 15)
// for that all even counts before 15 is/are (6,10) so we have 2 array with odd sum over there and
// 1 is complete subarray uptil 15 => so total subarrays ending at 15(prefix sum(1,2,3,4,5)) with sum odd are 3

// similarly 3 is just 1 array
// 1 just 1 array
//at 6 (which is even and it needs odd) => (6-1),(6-3) so 2 subarrays
//at 10 => (10-1), (10-3) so 2 subarrays
//at 21 => 21, 21-6, 21-10 so 3  subarrays
//at 21 => (28-1),(28-3),(28-15),(28-21) so 4 subarrays
//adding them up = 3+1+1+2+3+2+4 => 16
