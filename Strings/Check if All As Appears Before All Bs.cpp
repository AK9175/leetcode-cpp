class Solution {
public:
    bool checkString(string s) {
        int a = -1, b = s.length();
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'a') a = i;
            else if(b == s.length()) b = i;
        }
        if(a < b) return true;
        return false;
    }
};