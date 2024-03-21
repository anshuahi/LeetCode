#define pii pair<int, int>
#define pb push_back
#define ll long long int

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll topSum = 0;
        ll bottomSum = 0;
        for(auto x: grid[0]){
            topSum += x;
        }

        ll ans = LONG_MAX;
        for(int i = 0; i < n; i++){
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return ans;
    }
};