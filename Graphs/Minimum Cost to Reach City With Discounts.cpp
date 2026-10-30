// Minimum Cost to Reach City With Discounts  [Medium]

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<int>> dist(n, vector<int>(discounts+1, INT_MAX)); //Minimum distance required to visit a node within discounts
        vector<vector<pair<int, int>>> adjList(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int ans = INT_MAX;

        for(int i = 0 ; i < highways.size() ; i++){
            adjList[highways[i][0]].push_back({highways[i][1], highways[i][2]});
            adjList[highways[i][1]].push_back({highways[i][0], highways[i][2]});
        }

        dist[0][0] = 0;
        pq.push({0,0,0});

        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int distance = temp[0];
            int disc = temp[1];
            int node = temp[2];
            if (distance > dist[node][disc]) continue;
            if(node == n-1) return distance;
            for(auto itr : adjList[node]){
                int dest = itr.first;
                int cost = itr.second;
                if(disc + 1 <= discounts && dist[dest][disc + 1] > distance + (cost/2)){
                    pq.push({distance + (cost/2), disc + 1, dest});
                    dist[dest][disc+1] = distance + (cost/2);
                }
                if(dist[dest][disc] > distance + cost){
                    pq.push({distance + cost, disc, dest});
                    dist[dest][disc] = distance + cost;
                }
            }
        }
        
        return -1;

    }
};
