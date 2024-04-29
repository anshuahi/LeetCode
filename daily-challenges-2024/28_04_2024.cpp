/*
LeetCode-POTD: 834. Sum of Distances in Tree

POTD Link - https://leetcode.com/problems/sum-of-distances-in-tree/description/

*/

class Solution {
public:
    void dfs(int root, vector<vector<int>>& graph, vector<int>& count, vector<int>& ans, vector<bool>& visited) {
        visited[root] = true;
        for (auto child : graph[root]) {
            if (!visited[child]) {
                dfs(child, graph, count, ans, visited);
                count[root] += count[child];
                ans[root] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int root, vector<vector<int>>& graph, vector<int>& count, 
                vector<int>& ans, vector<bool>& visited) {
        visited[root] = true;
        for (auto child : graph[root]) {
            if (!visited[child]) {
                ans[child] = ans[root] - count[child] + count.size() - count[child];
                dfs2(child, graph, count, ans, visited);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> count(n, 1), ans(n, 0);
        vector<bool> visited(n, false);
        dfs(0, graph, count, ans, visited);
        visited.assign(n, false);
        dfs2(0, graph, count, ans, visited);
        return ans;
    }
};
