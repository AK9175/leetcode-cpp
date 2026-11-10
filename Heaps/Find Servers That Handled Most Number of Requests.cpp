class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        set<int> free;
        int maxi = INT_MIN;
        vector<int> ans;
        unordered_map<int, int> reqprocessed;
        for(int i = 0 ; i < k ; i++){
            free.insert(i);
        }

        for(int i = 0 ; i < arrival.size() ; i++){
            while(!busy.empty() && arrival[i] >= busy.top().first){
                free.insert(busy.top().second);
                busy.pop();
            }

            if(!free.empty()){
                auto itr = free.lower_bound(i%k);
                if(itr == free.end()){
                    itr = free.begin();
                }
                int serverid = *itr;
                busy.push({arrival[i]+load[i], serverid});
                reqprocessed[serverid]++;
                maxi = max(maxi, reqprocessed[serverid]);
                free.erase(itr);
            }
        }

        for(auto itr : reqprocessed){
            if(itr.second == maxi){
                ans.push_back(itr.first);
            }
        }

        return ans;
    }
};
