class Solution {
public:
    bool isCycle(vector<vector<int>> &v, vector<int> &vis, int i){
        // cout << i << " -> " << vis[i] << " ... ";
        if(vis[i] == 2)
            return true;
        vis[i] = 2;
        
        for(auto x : v[i]){
            if(vis[x] != 1)
                if(isCycle(v, vis, x))
                return true;
        }
        vis[i] = 1;
        return false;
    }

    void topological(vector<vector<int>> &v, vector<int> &ans, vector<bool> &vis, int f){
        if(vis[f]){
            return;
        }
        // cout << f << " ";
        vis[f] = true;
        for(int x : v[f]){
            // cout << x << " ";
            topological(v, ans, vis, x);
        }
        ans.push_back(f);
        // cout << endl;
    }

    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> v(num);
        for(auto p : pre){
            v[p[0]].push_back(p[1]);
        }
        
        vector<int> vis(num, 0);
        for(int i = 0; i < num; i++){
            if(vis[i] == 0){
                if(isCycle(v, vis, i))
                    return {};
            }
        }
        vector<bool> viss(num, false);
        for(int i = 0; i < num; i++){
            if(!viss[i]){
                // cout << i << " -> ";
                topological(v, ans, viss, i);
            }
        }

        return ans;
    }
};