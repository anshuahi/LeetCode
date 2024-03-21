// bool comp(vector<int> a, vector<int> b){
//     return a[1] < b[1];
//         // return true;
// }

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
    
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<vector<int>> v(num);
        for(auto p : pre){
            v[p[1]].push_back(p[0]);
        }
        
        vector<int> vis(num, 0);
        for(int i = 0; i < num; i++){
            if(vis[i] == 0){
                if(isCycle(v, vis, i))
                    return false;
            }
        }
        return true;;
    }
};