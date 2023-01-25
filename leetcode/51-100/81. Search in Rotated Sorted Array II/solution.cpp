class Solution {
public:
    
    bool searc(vector<int> &v, int t, int s, int e){
        if(s > e){
            return false;
        }
        
        cout << s << " " << e << endl;
        if(s == e)
            return v[s] == t;
        
        int m = (s+e)/2;
        if(v[m] == t || v[s] == t || v[e] == t)
            return true;
        
        int x = v[m];
        if(x > v[s]) {
            if(v[s] <= t && t < x){
                return searc(v, t, s, m-1);
            }
            return searc(v, t, m+1, e);
        }
        if(x < v[s]){
            if(x < t && t <= v[e]){
                return searc(v, t, m+1, e);
            }
            else {
                return searc(v, t, s, m-1);
            }
        }
        else {
            return searc(v, t, s+1, e);
        }
    }
    
    bool search(vector<int>& nums, int target) {
        return searc(nums, target, 0, nums.size()-1);
    }
};