class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<pair<int,int>> st;
        long long ans = 0;
        for(int i = 0 ; i < (int)nums.size() ; i++){
            while(!st.empty() && st.top().first > nums[i]){
                st.pop();
            }
            if(!st.empty() && st.top().first < nums[i]){
                ans += st.size();
                st.push({nums[i], st.size()});
                continue;
            }
            if(!st.empty() && st.top().first == nums[i]){
                ans += st.top().second;
                st.push({nums[i], st.top().second});
                continue;
            }
            if(st.empty()){
                st.push({nums[i], 0});
            }
        }
        return ans;
    }
};
// we need to find pair of all indexes iusing stack itself 
// and not n^2 loop(2 pointers), and then iterating on all elemengts in between these 2 indexes (A pair).

// 2 2 4 6
// (2 4) * 2
// (2 6) * 2
// (4,6)