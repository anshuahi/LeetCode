#define pb push_back
#define pii pair<int, int>

class Solution {
public:
    int ans;
    vector<int> parent;
    void Union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        if(parentX == parentY)
            return;
        parent[parentX] = parentY;
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n, 0);
        ans = 0;
        
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[vals[i]].push_back(i);
            parent[i] = i;
        }

        vector<vector<int>> gr(n);
        for(auto e: edges){
            gr[e[0]].pb(e[1]);
            gr[e[1]].pb(e[0]);
        }

        for(auto x: mp){
            int value = x.first;
            vector<int> nodes = x.second;       // nodes corresponds to value

            for(auto node: nodes){
                for(auto neighbor: gr[node]){
                    // choosing neighbor with less than or equal to value of node
                    if(vals[neighbor] <= vals[node])    
                        Union(node, neighbor);
                }
            }
            unordered_map<int, int> group;
            for(auto node: nodes){
                group[find(node)]++;
            }

            for(auto g: group){
                ans += (g.second*(g.second+1))/2;
            }
        }

        
        return ans;
    }
};












