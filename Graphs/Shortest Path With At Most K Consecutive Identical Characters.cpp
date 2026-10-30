class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));

        for(int i = 0 ; i < edges.size() ; i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        pq.push({0,0,1});
        dist[0][1] = 0;

        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int weight = temp[0];
            int node = temp[1];
            char nodeLabel = labels[node];
            // if(weight > dist[node][temp[2]]) continue;
            if(node == n-1) return weight;

            for(auto itr : adjList[node]){
                int dest = itr.first;
                int consequtiveCount = temp[2];
                char destLabel = labels[dest];
                int edgeweight = itr.second;
                if(nodeLabel == destLabel) consequtiveCount++;
                else consequtiveCount = 1;
                if(consequtiveCount > k || dist[dest][consequtiveCount] < weight + edgeweight) continue;
                dist[dest][consequtiveCount] = weight + edgeweight;
                pq.push({weight + edgeweight, dest, consequtiveCount});
            }
        }

        return -1;
    }
};
//  __________3_________
// |                    |
// |                    |   
// 0 ---1--->1----1---->2