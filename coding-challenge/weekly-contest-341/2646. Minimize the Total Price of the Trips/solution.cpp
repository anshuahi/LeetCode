// Genius Solution

#define pb push_back
#define pii pair<int, int>
#define ll long long
class Solution {
public:
    
    void dfs(int i, vector<int> &parent, vector<vector<int>> &gr, int target, bool &found){
        if(found)
            return;
        if(i == target){
            found = true;
            return;
        }
        
        for(auto x: gr[i]){
            if(x != parent[i]){
                parent[x] = i;
                dfs(x, parent, gr, target, found);
            }
        }
    }
    int count(int i, int parent, vector<vector<int>> &gr, vector<int> &price, bool inc){
        int ans = 0, b = 0;
        b = price[i];
        ans = price[i];
        if(inc && ans){
            ans = price[i]/2;
            for(auto x: gr[i]){
                if(x != parent){
                    ans += count(x, i, gr, price, false);
                }
            }
            for(auto x: gr[i]){
                if(x != parent){
                    b += count(x, i, gr, price, true);
                }
            }
            return min(ans, b);
            
        }

        for(auto x: gr[i]){
            if(x != parent){
                b += count(x, i, gr, price, true);
            }
        }
        return b;

        
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> gr(n);
        for(auto ed: edges){
            gr[ed[0]].pb(ed[1]);
            gr[ed[1]].pb(ed[0]);
        }
        
        vector<ll> cost(n);
        vector<int> parent(n);
        vector<int> times(n);
        int ans = 0;
        for(auto t: trips){
            parent.clear();
            parent.resize(n);
            int a = t[0], b = t[1];
            parent[a] = -1;
            bool found = false;
            dfs(a, parent, gr, b, found);
            while(b != -1){
                cost[b] += price[b];
                times[b]++;
                b = parent[b];
                
            }
        }
        for(int i = 0; i < n; i++){
            price[i] = times[i]*price[i];
        }
        
        return count(0, -1, gr, price, true);
        
    }
};