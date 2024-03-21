#define pii pair<int, int>
#define ppii pair<int, pii>
#define pb push_back
class Solution {
public:
    
    bool isValid(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >=m){
            return false;
        }
        return true;
    }
    void print(vector<vector<int>>& g){
        for(auto x: g){
            for(auto y: x){
                if(y == INT_MAX){
                    y = -1;
                }
                cout << y << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int minimumTime(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        if(g[0][1] > 1 && g[1][0] > 1){
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<ppii, vector<ppii>, greater<ppii>> q;
        q.push({0, {0, 0}});
        dp[0][0] = 0;
        while(!q.empty()){
            ppii p = q.top(); q.pop();
            int time = p.first;
            int i = p.second.first, j = p.second.second;
            if(i == n-1 && j == m-1){
                break;
            }
            time++;
            int x = i-1, y = j;
            if(isValid(x, y, n, m)){
                int diff = g[x][y] - time;
                int ownTime = time;
                if(diff > 0){
                    diff = (diff+1)/2;
                    diff *= 2;
                }
                else {
                    diff = 0;
                }
                ownTime += diff;
                // cout << x <<" " <<y <<" "<< g[x][y] << " -> " << ownTime<< endl;
                // if(g[x][y] <= ownTime){
                if(dp[x][y] > ownTime){
                    dp[x][y] = ownTime;
                    q.push({dp[x][y], {x, y}});
                }
                // }
            }
            x = i+1, y = j;
            if(isValid(x, y, n, m)){
                int diff = g[x][y] - time;
                int ownTime = time;
                if(diff > 0){
                    diff = (diff+1)/2;
                    diff *= 2;
                }
                else {
                    diff = 0;
                }
                ownTime += diff;
                // if(g[x][y] <= ownTime){
                if(dp[x][y] > ownTime){
                    dp[x][y] = ownTime;
                    q.push({dp[x][y], {x, y}});
                }
                // }
            }
            x = i, y = j-1;
            if(isValid(x, y, n, m)){
                int diff = g[x][y] - time;
                int ownTime = time;
                if(diff > 0){
                    diff = (diff+1)/2;
                    diff *= 2;
                }
                else {
                    diff = 0;
                }
                ownTime += diff;
                // if(g[x][y] <= ownTime){
                if(dp[x][y] > ownTime){
                    dp[x][y] = ownTime;
                    q.push({dp[x][y], {x, y}});
                }
                // }
            }
            x = i, y = j+1;
            if(isValid(x, y, n, m)){
                int diff = g[x][y] - time;
                int ownTime = time;
                if(diff > 0){
                    diff = (diff+1)/2;
                    diff *= 2;
                }
                else {
                    diff = 0;
                }
                ownTime += diff;
                // if(g[x][y] <= ownTime){
                if(dp[x][y] > ownTime){
                    dp[x][y] = ownTime;
                    q.push({dp[x][y], {x, y}});
                }
                // }
            }
            // print(dp);
        }
        
        return dp[n-1][m-1];
    }
};