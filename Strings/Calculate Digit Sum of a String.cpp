class Solution {
public:
    string digitSum(string s, int k) {
        string ans = "";
        int tempk = 0;
        while(s.length() > k){
            tempk = k;
            int sum = 0, i = 0;
            while(tempk && i < s.length()){
                tempk--;
                sum += s[i] - '0';
                if(tempk == 0){
                    ans += to_string(sum);
                    tempk = k;
                    sum = 0;
                }
                i++;
            }
            if(i == s.length()){
                if(tempk != k) ans += to_string(sum);
                s = ans;
                ans = "";
            }
        }
        return s;
    }
};