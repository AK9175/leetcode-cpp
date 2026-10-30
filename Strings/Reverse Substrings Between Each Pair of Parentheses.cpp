class Solution {
public:
    string reverseParentheses(string s) {
        int step = 1;
        stack<int> st;
        unordered_map<int, int> mp;
        string ans = "";

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                mp[st.top()] = i;
                mp[i] = st.top();
                st.pop();
            }
        }

        int ind = 0;

        while(ind >= 0 && ind < s.length()){
            if(s[ind] != '(' && s[ind] != ')'){
                ans += s[ind];
                if(step) ind++;
                else ind--;
            }
            else{
                ind = mp[ind];
                if(step == 1) step = 0;
                else step = 1;

                if(step) ind++;
                else ind--;
            }
        }

        return ans;
    }
};