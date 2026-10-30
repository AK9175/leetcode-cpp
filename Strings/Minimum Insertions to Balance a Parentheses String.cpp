class Solution {
public:
    int minInsertions(string s) {
        vector<int> st;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(!st.empty() && i+1 < s.length() && s[i] == ')' && s[i+1] == ')' && st.back() == i-1 && s[st.back()] == '('){
                st.pop_back();
                i++;
            }
            else st.push_back(i);
        }

    }
};