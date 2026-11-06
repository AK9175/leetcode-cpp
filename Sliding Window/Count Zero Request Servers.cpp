class Solution {
public:

// n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]

    static bool Compare(const vector<int> a, const vector<int> b){
        if(a[1] < b[1]) return true;
        return false; 
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        unordered_map<int,int> freq;
        int count = 0, qsize = queries.size(), left = 0, right = 0;
        vector<int> ans(qsize);
        vector<vector<int>> intervals(qsize, vector<int>(3,0));
        sort(logs.begin(), logs.end(), Compare);

        for(int i = 0 ; i < qsize ; i++){
            intervals[i][0] = queries[i] - x;
            intervals[i][1] = queries[i];
            intervals[i][2] = i;
        }

        for(int i = 1 ; i <= n ; i++){
            freq[i] = 0;
        }

        sort(intervals.begin(), intervals.end());

        auto ileft = lower_bound(logs.begin(), logs.end(), intervals[0][0], [](const vector<int>& log, int t){ return log[1] < t; });
        auto iright = upper_bound(logs.begin(), logs.end(), intervals[0][1], [](int t, const vector<int>& log){ return t < log[1]; });

        if(ileft != logs.end()) left = ileft - logs.begin();
        else left = logs.size(); 

        if(iright != logs.end()) right = iright - logs.begin();
        else right = logs.size();

        for(int i = left ; i < right && i < logs.size() ; i++){
            freq[logs[i][0]]++;
            if(freq[logs[i][0]] == 1) count++;
        }

        ans[intervals[0][2]] = n-count;

        for(int i = 1 ; i < intervals.size() ; i++){
            while(left < logs.size() && logs[left][1] < intervals[i][0]){
                freq[logs[left][0]]--;
                if(freq[logs[left][0]]==0) count--;
                left++;
            }

            while(right < logs.size() && logs[right][1] <= intervals[i][1]){
                freq[logs[right][0]]++;
                if(freq[logs[right][0]]==1) count++;
                right++;
            }

            ans[intervals[i][2]] = n-count;
        }

        return ans;
    }
};
