// 1167. Minimum Cost to Connect Sticks  [Medium]

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        if(sticks.size() == 1) return 0;
        for(int i = 0 ; i < (int)sticks.size() ; i++){
            pq.push(sticks[i]);
        }

        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            pq.push(first+second);
            ans += first + second;
        }
        return ans;
    }
};
