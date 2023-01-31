#define pii pair<int,int>
#define pb push_back
#define ll long long int


class Solution {
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> v;
        int n = scores.size();
        for(int i = 0; i < n; i++){
            v.pb({ages[i], scores[i]});
        }

        sort(v.begin(), v.end());

        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
            ans = max(ans, dp[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(v[j].second <= v[i].second){
                    dp[i] = max(v[i].second + dp[j], dp[i]);
                }
            }
            ans = max(dp[i], ans);
        }

        return ans;

        // return findBestTeam(0, 0, v);
    }
};