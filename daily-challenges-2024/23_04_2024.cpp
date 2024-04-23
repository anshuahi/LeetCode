/*
LeetCode-POTD: 310. Minimum Height Trees

POTD Link - https://leetcode.com/problems/minimum-height-trees/description/

Approach :
    1. try to cut all nodes with one degree
    2. reduce the degree of the respective nodes
    3. repeat the step 1 till all nodes are separated
    4. return the last nodes remaining
*/

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        if (n == 2)
        {
            return {0, 1};
        }
        vector<int> degree(n);
        vector<vector<int>> gr(n);
        for (auto edge : edges)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }

        while (!q.empty())
        {
            ans.clear();
            int sz = q.size();
            while (sz--)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto nbr : gr[node])
                {
                    degree[nbr]--;
                    if (degree[nbr] == 1)
                        q.push(nbr);
                }
            }
        }
        return ans;
    }
};
