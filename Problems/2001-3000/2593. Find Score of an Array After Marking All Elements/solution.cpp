#define ll long long int
#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    long long findScore(vector<int>& v) {
        int n = v.size();
        vector<bool> vis(n);
        
        priority_queue<pii, vector<pii>, greater<pii> > p;
        for(int i = 0; i < n; i++){
            p.push({v[i], i});
        }
        
        ll ans = 0;
        while(!p.empty()){
            pii t = p.top();
            p.pop();
            int val = t.first, ind = t.second;
            if(vis[ind]){
                continue;
            }
            ans += 1LL*val;
            vis[ind] = true;
            if(ind-1 >= 0){
                vis[ind-1] = true;
            }
            if(ind+1 < n){
                vis[ind+1] = true;
            }
            
        }
        
        return ans;
    }
};