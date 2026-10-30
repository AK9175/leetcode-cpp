class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        sort(temp.begin(), temp.end());
        if(temp == s) return 0;
        if(s.size() == 2 || s.size() == 1) return -1;
        if((temp[0] == s[0] || temp[s.size()-1] == s[s.size()-1])) return 1;
        if(s.size() >= 3 && temp[0] == s[s.size()-1] && temp[s.size()-1] == s[0]){
            char first = s[0], last = s[s.size()-1];
            for(int i = 1; i < s.size()-1 ; i++){
                if(s[i] == first || s[i] == last) return 2;
            }
        }    
        return 3;
    }
};

// card 
// cadr
// acdr
// acdr

// ahgfdcba
// aabcdfgh
// for this question maximum answer will be 3

// ab c de f gh
// ba c ed f hg 

// aaabaa
// aaaaab

//dbca //dabc //abdc // abcd
//dbca //bcda //bacd //abcd  
//abc

//zabc //abzc //abcz 

// bbbaaa baaabb aaabbb

// aaabbb