class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = queryIP.size();
        int left = -1;
        bool dot = false, colon = false;
        vector<string> temp;

        for(int right = 0 ; right < n ; right++){
            if(queryIP[right] == '.'){
                dot = true;
                temp.push_back(queryIP.substr(left+1, (right-left-1)));
                left = right;
            }
            if(queryIP[right] == ':'){
                colon = true;
                temp.push_back(queryIP.substr(left+1, (right-left-1)));
                left = right;
            }
            if(colon && dot) return "Neither";
        }
        temp.push_back(queryIP.substr(left+1));

        if(temp.size() == 4){
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i].length() > 3 || temp[i].length() == 0) return "Neither";
                for(int j = 0 ; j < temp[i].length() ; j++){
                    if(temp[i].size() > 1 && (j == 0 && temp[i][j] == '0') || isalpha(temp[i][j])) return "Neither";
                }
                if(temp[i].size() == 3 && stoi(temp[i]) > 255) return "Neither";
            }
            return "IPv4";
        }

        if(temp.size() == 8){
            for(int i = 0 ; i < temp.size() ; i++){
                if(temp[i].length() == 0 || temp[i].length() > 4) return "Neither";
                for(int j = 0 ; j < temp[i].length() ; j++){
                    if(temp[i][j] >= 'g' && temp[i][j] <= 'z' 
                    || temp[i][j] >= 'G' && temp[i][j] <= 'Z'){
                        return "Neither";
                    }
                }
            }
            return "IPv6";
        }

        return "Neither";
        
    }
};