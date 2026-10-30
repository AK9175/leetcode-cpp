class Solution {
public:
    set<string> ans;

    bool isValid(string s){
        vector<char> st;
        for(int i = 0 ; i < s.length() ; i++){
            if(!st.empty() && s[i] == ')' && st.back() == '(') st.pop_back();
            else if(s[i] == '(' || s[i] == ')') st.push_back(s[i]);
        }
        if(st.empty()) return true;
        return false;
    }

    string trim(string s, int i){
        return s.substr(0,i) + s.substr(i+1);
    }

    void dfs(int i, int j, string s, vector<char> &st){
        if(j == st.size() && isValid(s)){
            ans.insert(s);
            return;
        }
        else if(j == st.size()) return;

        for(int ind = i ; ind < s.size() ; ind++){
            if(s[ind] == st[j]){
                dfs(ind,j+1,trim(s,ind),st);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<char> st;
        for(int i = 0 ; i < s.length() ; i++){
            if(!st.empty() && s[i] == ')' && st.back() == '(') st.pop_back();
            else if(s[i] == '(' || s[i] == ')') st.push_back(s[i]);
        }

        dfs(0, 0, s, st);
        return vector<string>(ans.begin(), ans.end());
    }
};
