class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st;
        int ans = 0;
        st.push_back(-1);
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') st.push_back(i);
            else if(s[i] == ')'){
                if(!st.empty() && st.back() != -1 && s[st.back()] == '(') st.pop_back();
                else st.push_back(i);
            }
        }
        st.push_back(s.length());

        for(int i = 1 ; i < st.size() ; i++){
            ans = max(ans, st[i] - st[i-1] - 1);
        }

        return ans;
    }
};