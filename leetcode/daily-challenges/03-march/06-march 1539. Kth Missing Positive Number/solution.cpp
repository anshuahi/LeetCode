class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();
        int count = 0;
        int i;
        vector<bool> vis(2001);
        for(auto x: v){
            vis[x] = true;
        }
        for(int i = 1; i < vis.size(); i++){
            if(!vis[i]){
                count++;
                if(count == k)
                    return i;
            }
        }
        return -1;
    }
};