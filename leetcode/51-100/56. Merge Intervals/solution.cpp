#define pb push_back

class Solution {
public:
    
    bool overlap(vector<int> a, vector<int> b){
        if(a[0] <= b[0] && b[0] <= a[1])
            return true;
        
        if(b[0] <= a[0] && a[0] <= b[1])
            return true;
        
        return false;
    }
    
    vector<vector<int>> interval(vector<vector<int>>& v) {
        bool b = false;
        
        vector<vector<int>> p;
        p.pb(v[0]);
        for(int i = 1; i < v.size(); i++){
            vector<int> v1 = p[p.size()-1];
            if(overlap(v1, v[i])){
                p[p.size()-1] = {min(v[i][0], v1[0]), max(v[i][1], v1[1])};
            }
            else {
                p.pb(v[i]);
            }
        }
        
        
        if(b){
            return interval(p);
        }
        return p;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        return interval(v);
    }
};