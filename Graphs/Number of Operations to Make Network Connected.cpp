// 1319. Number of Operations to Make Network Connected  [Medium]

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int extraedges = 0;
    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]); 
    }

    void join(int left, int right){
        int leftParent = find(left);
        int rightParent = find(right);
        if(leftParent == rightParent){
            extraedges++;
            return;
        }
        if(rank[leftParent] > rank[rightParent]){
            parent[rightParent] = leftParent;
            rank[leftParent]++;
        }
        else {
            parent[leftParent] = rightParent;
            rank[rightParent]++;
        }
    }

    int noOfConnectedComponents(){
        int cnt = 0;
        for(int i = 0 ; i < (int)parent.size() ; i++){
            if(find(parent[i]) == i) cnt++;
        }
        return cnt;
    }

    int extraEdges(){
        return extraedges;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        for(int i = 0 ; i < (int)connections.size() ; i++){
            dsu.join(connections[i][0], connections[i][1]);
        }
        if(dsu.noOfConnectedComponents() - 1 > dsu.extraEdges()) return -1;
        return dsu.noOfConnectedComponents() - 1;
    }
};
