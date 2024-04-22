/*
LeetCode-POTD: 1971. Find if Path Exists in Graph

POTD Link - https://leetcode.com/problems/find-if-path-exists-in-graph/description/

Approach :
    1. Use UnionFind Algo
    2. union of all given edges
    3. check if find i.e. parent of source and destination are same

*/
class Solution
{
    class UnionFind
    {
        int parent[];
        UnionFind(int n)
        {
            parent = new int[n];
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int node)
        {
            if (node == parent[node])
                return node;
            return parent[node] = find(parent[node]);
        }

        void merge(int a, int b)
        {
            int parentA = find(a);
            int parentB = find(b);
            parent[parentA] = parentB;
            parent[a] = parentB;
        }
    }

    public boolean
    validPath(int n, int[][] edges,
              int source, int destination)
    {
        UnionFind unionFind = new UnionFind(n);
        for (int[] edge : edges)
        {
            unionFind.merge(edge[0], edge[1]);
        }
        return unionFind.find(source) == unionFind.find(destination);
    }
}
