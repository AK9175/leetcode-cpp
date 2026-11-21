// 3331. Find Subtree Sizes After Changes  [Medium]

class Solution {
public:

    int dfscount(int i, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &ans){
        int count = 0;
        for(int node : adjList[i]){
            count += dfscount(node, adjList, visited, ans);
        }
        ans[i] = count + 1;
        visited[i] = 1;
        return ans[i];
    }

    void dfs(int i, vector<vector<int>> &adjList, vector<int> &occurance, const string& s, vector<int> &ancestor, vector<int> &visited){
        if(occurance[s[i]-'a'] != -1) ancestor[i] = occurance[s[i]-'a'];
        int oldoccurance = occurance[s[i]-'a'];
        occurance[s[i]-'a'] = i;
        for(int node : adjList[i]){
            dfs(node, adjList, occurance, s, ancestor, visited);
        }
        occurance[s[i]-'a'] = oldoccurance;
        visited[i] = 1;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adjList(n);
        vector<vector<int>> newAdjList(n);
        vector<int> ancestor(n, -1);
        vector<int> occurance(26, -1);
        vector<int> visited(n,-1);
        vector<int> ans(n, 1);
        for(int i = 1 ; i < n ; i++){
            adjList[parent[i]].push_back(i);
        }

        //Calculate the immediate closest ancestor sharing the same character by this DFS Approach
        for(int i = 0 ; i < n ; i++){
            if(visited[i] != 1) dfs(i, adjList, occurance, s, ancestor, visited);
        }


        //Now according to the calculated closest ancestors change their parents
        for(int i = 0 ; i < n ; i++){
            if(ancestor[i] != -1) parent[i] = ancestor[i];
            visited[i] = -1;
        }

        for(int i = 1 ; i < n ; i++){
            newAdjList[parent[i]].push_back(i);
        }

        for(int i = 0 ; i < n ; i++){
            if(visited[i] != 1) ans[i] = dfscount(i, newAdjList, visited, ans);
        }

        return ans;
    }
};
