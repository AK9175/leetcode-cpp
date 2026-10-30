#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    int timer;

    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> depth;
    vector<int> subtreeSize;
    vector<int> heavyChild;
    vector<int> head;
    vector<int> position;
    vector<int> nodeMask;

    class BIT {
    private:
        int n;
        vector<int> tree;

    public:
        BIT(int n) : n(n), tree(n + 1, 0) {}

        void update(int index, int value) {
            while (index <= n) {
                tree[index] ^= value;
                index += index & -index;
            }
        }

        int prefixXor(int index) {
            int result = 0;

            while (index > 0) {
                result ^= tree[index];
                index -= index & -index;
            }

            return result;
        }

        int rangeXor(int left, int right) {
            return prefixXor(right) ^ prefixXor(left - 1);
        }
    };

    int dfsSize(int node, int par) {
        parent[node] = par;
        subtreeSize[node] = 1;

        int largestSubtree = 0;

        for (int neighbor : graph[node]) {
            if (neighbor == par) {
                continue;
            }

            depth[neighbor] = depth[node] + 1;

            int childSize = dfsSize(neighbor, node);

            subtreeSize[node] += childSize;

            if (childSize > largestSubtree) {
                largestSubtree = childSize;
                heavyChild[node] = neighbor;
            }
        }

        return subtreeSize[node];
    }

    void dfsHLD(int node, int chainHead) {
        head[node] = chainHead;
        position[node] = ++timer;

        if (heavyChild[node] != -1) {
            dfsHLD(heavyChild[node], chainHead);
        }

        for (int neighbor : graph[node]) {
            if (neighbor == parent[node] ||
                neighbor == heavyChild[node]) {
                continue;
            }

            dfsHLD(neighbor, neighbor);
        }
    }

    int queryPath(int u, int v, BIT& bit) {
        int result = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                result ^= bit.rangeXor(
                    position[head[u]],
                    position[u]
                );

                u = parent[head[u]];
            } else {
                result ^= bit.rangeXor(
                    position[head[v]],
                    position[v]
                );

                v = parent[head[v]];
            }
        }

        int left = min(position[u], position[v]);
        int right = max(position[u], position[v]);

        result ^= bit.rangeXor(left, right);

        return result;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        timer = 0;

        graph.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        subtreeSize.assign(n, 0);
        heavyChild.assign(n, -1);
        head.assign(n, 0);
        position.assign(n, 0);
        nodeMask.assign(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfsSize(0, -1);
        dfsHLD(0, 0);

        BIT bit(n);

        for (int node = 0; node < n; node++) {
            nodeMask[node] = 1 << (s[node] - 'a');

            bit.update(
                position[node],
                nodeMask[node]
            );
        }

        vector<bool> answer;

        for (string& query : queries) {
            stringstream input(query);

            string type;
            int u;
            string value;

            input >> type >> u >> value;

            if (type == "update") {
                int newMask = 1 << (value[0] - 'a');

                int change = nodeMask[u] ^ newMask;

                bit.update(
                    position[u],
                    change
                );

                nodeMask[u] = newMask;
            } else {
                int v = stoi(value);

                int pathMask = queryPath(u, v, bit);

                bool canFormPalindrome =
                    (pathMask & (pathMask - 1)) == 0;

                answer.push_back(canFormPalindrome);
            }
        }

        return answer;
    }
};