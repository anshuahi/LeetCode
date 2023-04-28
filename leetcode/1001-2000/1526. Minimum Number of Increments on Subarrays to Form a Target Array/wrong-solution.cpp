#define pb push_back
class Solution {
public:

    vector<int> duplicate(vector<int> &v){
        vector<int> a;
        a.pb(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(v[i] != v[i-1]){
                a.pb(v[i]);
            }
        }
        return a;
    }

    int operations(vector<int> &v){
        int mn = INT_MAX;
        int n = v.size();
        vector<int> a;
        for(int i = 0; i < n; i++){
            mn = min(mn, v[i]);
        }
        int ans = mn;
        for(int i = 0; i < n; i++){
            v[i] -= mn;
        }

        if(v[0] > v[1]){
            a.pb(0);
        }
        for(int i = 1; i < n-1; i++){
            if(v[i] > v[i-1] && v[i] > v[i+1]){
                a.pb(i);
            }
        }
        if(v[n-1] > v[n-2]){
            a.pb(n-1);
        }

        // int ans = 0;
        for(auto x: a){
            ans += v[x];
        }
        return ans;
    }

    int minNumberOperations(vector<int>& target) {
        target = duplicate(target);
        int n = target.size();
        vector<int> nextSmall(n, 1);
        stack<int> s;

        for(int i = 0; i < n; i++){
            while(!s.empty() && target[s.top()] > target[i]){
                nextSmall[s.top()] = target[i];
                s.pop();
            }
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += target[i] - nextSmall[i];
            // cout << ans << " ";
        }

        return ans;
    }
};
