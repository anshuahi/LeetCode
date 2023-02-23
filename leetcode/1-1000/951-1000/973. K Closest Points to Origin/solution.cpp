#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0], y = points[i][1];
            q.push({x*x+y*y, i});
        }
        vector<vector<int>>  ans;
        while(!q.empty() && k > 0){
            ans.pb(points[q.top().second]);
            q.pop();
            k--;
        }
        return ans;
    }
};