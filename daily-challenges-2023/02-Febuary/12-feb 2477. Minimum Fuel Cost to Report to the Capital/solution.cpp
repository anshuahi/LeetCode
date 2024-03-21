#define pb push_back
#define pii  pair<int, int>
#define ll long long int
class Solution {
public:
    ll ans;

    int dfs(int node, int parent, vector<vector<int>> &gr, int &seats){
        int num = 1;
        ll p = 0;
        for(auto x: gr[node]){
            if(x != parent){
                p = dfs(x, node, gr, seats);
                ans += ceil(p*1.0/seats);
                num += p;
            }
        }
        return num;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<int> dist(n, INT_MAX);
        vector<vector<int>> gr(n);
        vector<bool> vis(n);
        for(auto ed: roads){
            gr[ed[0]].pb(ed[1]);
            gr[ed[1]].pb(ed[0]);
        }
        ans = 0;
        dfs(0, -1, gr, seats);
        return ans;
    }
};

