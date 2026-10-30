class Solution {
public:



    vector<int> minStationsAndRoads(int n, vector<vector<int>>& roads, vector<int>& stations, int source, int destination, int p) {
        vector<vector<int>> adjList(n, vector<int>({}));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;// <stations, roads, fuel, node>
        vector<bool> isFuelStation(n, false);
        vector<int> bestFuel(n, INT_MIN);
        for(int i = 0 ; i < roads.size(); i++){
            adjList[roads[i][0]].push_back(roads[i][1]);
            adjList[roads[i][1]].push_back(roads[i][0]);
        }                  
        
        for(int i = 0 ; i < stations.size() ; i++){
            isFuelStation[stations[i]] = true;
        }

        pq.push({0,0,p,source});
        bestFuel[source] = p;
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int noOfstn = temp[0], road = temp[1], fuelleft = temp[2], src = temp[3];
            if(src == destination) return {noOfstn, road};
            if(!fuelleft) continue;
            for(int i = 0 ; i < adjList[src].size() ; i++){
                if(isFuelStation[adjList[src][i]]){
                    if(bestFuel[adjList[src][i]] < p){
                        pq.push({noOfstn + 1, road + 1, p, adjList[src][i]});
                        bestFuel[adjList[src][i]] = p;
                    }
                }
                else{
                    if(bestFuel[adjList[src][i]] < fuelleft - 1){
                        pq.push({noOfstn, road + 1, fuelleft - 1, adjList[src][i]});
                        bestFuel[adjList[src][i]] = fuelleft - 1;
                    }
                }

            }

        }

        return {-1, -1};
    }
};
