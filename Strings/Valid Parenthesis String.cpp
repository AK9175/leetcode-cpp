class Solution {
public:
    bool checkValidString(string s) {
        vector<int> brackets;
        vector<int> stars;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') brackets.push_back(i);
            else if(s[i] == ')' && !brackets.empty() && s[brackets.back()] == '(') brackets.pop_back();
            else if(s[i] == '*') stars.push_back(i);
            else brackets.push_back(i);
        }
        if(brackets.size() > stars.size()) return false;
        if(brackets.size() == 0) return true;
        int bind = 0, sind = 0;

        while(bind < brackets.size() && sind < stars.size()){
            if(s[brackets[bind]] == '('){
                if(stars[sind] > brackets[bind]) sind++;
                else{
                    while(sind < stars.size() && stars[sind] < brackets[bind]){
                        sind++;
                    }
                    if(sind == stars.size()) return false;
                    sind++;
                }
            }
            else if(s[brackets[bind]] == ')'){
                if(stars[sind] < brackets[bind]){
                    sind++;
                }
                else return false;
            }
            bind++;
        }
        cout<<"A";
        if(bind < brackets.size()) return false;
        return true;
    }
};