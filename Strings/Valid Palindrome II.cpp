class Solution {
public:

    bool checkPalindrome(string s1){
        int left = 0, right = s1.length()-1;
        while(left <= right){
            if(s1[left] == s1[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while(left <= right){
            if(s[left] == s[right]){
                left++;
                right--;
            }
            else break;
        }

        if(left >= right || checkPalindrome(s.substr(left, right-left)) || checkPalindrome(s.substr(left+1, right-left))) return true;
        return false;
    }
};