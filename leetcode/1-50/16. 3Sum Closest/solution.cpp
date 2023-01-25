class Solution {
public:
    
    int ans;
    int diff;
    
    int threeSumClosest(vector<int>& v, int tr) {
        sort(v.begin(), v.end());
        int t = tr;
        diff = INT_MAX;
        ans = -1;
        for(int i = 0; i < v.size(); i++){
            
            t = tr - v[i];
            int s = i+1, e = v.size()-1;
            
            while(s < e){
                int x = v[s] + v[e];
                if(diff > abs(tr - x - v[i])){
                    diff = abs(tr - x - v[i]);
                    ans = x+v[i];
                }
                if(x == t){
                    return tr;
                }
                if(x < t){
                    s++;
                }
                else {
                    e--;
                }
            }
        }
        return ans;
    }
};