class Solution {
public:

    bool checkAnagram(vector<int> &sfreq, vector<int> &pfreq){
        for(int i = 0 ; i < 26 ; i++){
            if(sfreq[i] != pfreq[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> sfreq(26, 0);
        vector<int> pfreq(26,0);
        vector<int> ans;
        int pl = p.length(), sl = s.length();
        int left = 0, right = 0;
        if(sl < pl) return ans;
        for(int i = 0 ; i < pl ; i++){
            pfreq[p[i]-'a']++;
            sfreq[s[i]-'a']++;
        }

        right = pl-1;
        while(left <= sl-pl){
            if(checkAnagram(sfreq, pfreq)){
                ans.push_back(left);
            }
            right++;
            if(right >= sl) break;
            sfreq[s[left]-'a']--;
            sfreq[s[right]-'a']++;
            left++;
        }

        return ans;
    }
};
