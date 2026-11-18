class Solution {
public:
    int minChanges(string s) {
        vector<int> ones, zeroes;
        int zeroCnt = 0, oneCnt = 0, n = s.length();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0')zeroCnt++;
            else oneCnt++;
            zeroes.push_back(zeroCnt);
            ones.push_back(oneCnt);
        }

        for(int i = 1 ; i < n ; i += 2){
            if(i-2 < 0){
                ans += min(zeroes[i]-0, ones[i]-0);
            }
            else{
                ans += min(zeroes[i]-zeroes[i-2], ones[i]-ones[i-2]);
            }
        }

        return ans;
        
    }
};
