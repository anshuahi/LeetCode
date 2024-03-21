class Solution {
public:
    int minimumDeviation(vector<int>& v) {
        int l = v[0], r = v[0];
        int n = v.size();
        int mn = INT_MAX;
        priority_queue<int> p;
        for(auto x: v){
            int y = x%2 == 1? x*2: x;
            mn = min(mn, y);
            p.push(y);
        }
        int ans = INT_MAX;
        while(!p.empty()){
            int t = p.top(); p.pop();
            ans = min(ans, t-mn);
            if(t%2 == 1){
                break;
            }
            mn = min(mn, t/2);
            p.push(t/2);
        }

        return ans;
    }
};