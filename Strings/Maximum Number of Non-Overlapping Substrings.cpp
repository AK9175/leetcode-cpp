// 1520. Maximum Number of Non-Overlapping Substrings  [Hard]

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> freq(26, vector<int>(2, -1));
        vector<vector<int>> intervals;
        vector<vector<int>> mergefinal;
        vector<string> ans;
        int len = INT_MAX;
        for(int i = 0 ; i < (int) s.length() ; i++){
            int ind = s[i] - 'a';
            if(freq[ind][0] == -1){
                freq[ind][0] = i;
                freq[ind][1] = i;
            }
            else freq[ind][1] = i;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i][0] != -1 && freq[i][1] != -1){
                bool valid = true;
                for(int j = freq[i][0]+1 ; j < freq[i][1] ; j++){
                    if(freq[s[j]-'a'][0] < freq[i][0]){
                        valid = false;
                        break;
                    }
                    freq[i][1] = max(freq[i][1], freq[s[j]-'a'][1]);
                }
                if(valid) intervals.push_back({freq[i][0], freq[i][1]});
            }
        }
        
        

        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){ return a[1] < b[1]; });
        for(int i = 0 ; i < (int)intervals.size() ; i++){
            vector<vector<int>> merge;
            int totallen = 0;
            merge.push_back({intervals[i]});
            totallen += intervals[i][1] - intervals[i][0] + 1;
            for(int j = i+1 ; j < (int)intervals.size() ; j++){
                if(merge.back()[1] < intervals[j][0]){
                    merge.push_back(intervals[j]);
                    totallen += intervals[j][1] - intervals[j][0] + 1;
                }
            }
            if((merge.size() > mergefinal.size()) || (merge.size() == mergefinal.size() && len > totallen)){
                mergefinal = merge;
                len = totallen;
            }
        }

        for(int i = 0 ; i < (int) mergefinal.size() ; i++){
            ans.push_back(s.substr(mergefinal[i][0], mergefinal[i][1] - mergefinal[i][0] + 1));
        }
        if(ans.size() == 0) return {s};
        return ans;
    }
};
