//  s = "hi(name)", knowledge = [["a","b"]]
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int left = 0 , right = 0;
        unordered_map<string, string> mp;

        for(int i = 0 ; i < knowledge.size() ; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string temp = "";
        while(left <= right && right < s.length()){
            if(s[left] == '(' && s[right] != ')')right++;
            else if(s[left] == '(' && s[right] == ')'){
                string key = s.substr(left+1, right-left-1);
                if(!mp.count(key)){
                    temp += '?';
                }
                else{
                    temp += mp[key];
                }
                right++;
                left = right;
            }
            else {
                temp += s[right];
                left++;
                right++;
            }
        }
        return temp;
    }
};