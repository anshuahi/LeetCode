class Solution {
public:

    void dfs(int i, vector<vector<int>>& gr, vector<bool> &vis, vector<bool> &apple, int &apples, int & dept){
        if(vis[i])
            return;
        vis[i] = true;
        for(auto x: gr[i]){
            if(!vis[x]){
            int apple = 0;
            int depth = 0;
            dfs(x, gr, vis, apple, apple, depth);
                if(apple){
                    dept += depth+2;
                    apples += apple;
                }
            }
        }
        if(apple[i]){
            apples++;
        }

        vis[i] = false;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> gr(n);
        for(auto x: edges){
            gr[x[0]].push_back(x[1]);
            gr[x[1]].push_back(x[0]);
        }
        int apple = 0;
        int depth = 0;
        vector<bool> vis(n, false);
        dfs(0, gr, vis, hasApple, apple, depth);
        return depth;
    }
};