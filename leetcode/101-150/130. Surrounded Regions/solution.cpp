#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    bool isValid(int a, int b, int n, int m ){
        if(a < 0 || b < 0 || a >= n || b >= m){
            return false;
        }
        return true;
    }
    void solve(vector<vector<char>>& br) {
        int n = br.size(), m = br[0].size();
        // vector<vector<char>> c(n, vector<char>(m, 'O'));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pii> q;
        for(int i = 0; i < n; i++){
            if(br[i][0] == 'O'){
                q.push({i, 0});
            }
            if(br[i][m-1] == 'O'){
                q.push({i, m-1});                
            }
        }
        for(int i = 0; i < m; i++){
            if(br[0][i] == 'O'){
                q.push({0, i});
            }
            if(br[n-1][i] == 'O'){
                q.push({n-1, i});                
            }
        }

        while(!q.empty()){
            pii p = q.front(); q.pop();
            int a = p.first, b = p.second;
            if(!isValid(a, b, n, m) || vis[a][b] || br[a][b] == 'X'){
                continue;
            }
            
            vis[a][b] = true;

            q.push({a-1, b});
            q.push({a+1, b});
            q.push({a, b-1});
            q.push({a, b+1});
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    br[i][j] = 'X';
                }
            }
        }

    }
};












