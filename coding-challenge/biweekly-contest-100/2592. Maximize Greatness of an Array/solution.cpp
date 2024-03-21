class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        
        vector<bool> vis(n);
        int left = 1;
        int ans = 0;
        for(int i = 0; i < n && left < n; i++){
            while(left < n){
                if(vis[left] == true || v[left]  == v[i]){
                    left++;
                    continue;
                }
                else {
                    break;
                }
            }
            if(left < n)
                vis[left] = true;
        }
        for(auto x: vis){
            if(x)
                ans++;
        }
        return ans;
    }
};