#define pb push_back

class Solution {
public:
    
    // find index to insert new intervals
    int addPointInSortedOrder(vector<vector<int>>& in, int s, int e, vector<int>& ne) {
        while(s <= e){
            int m = (s+e)/2;
            if(in[m][0] == ne[0]){
                return m;
            }
            if(in[m][0] < ne[0]){
                s++;
            }
            else {
                e--;
            }
        }
        
        return s;
    }
    
    // check if the two intervals overlap
    bool overlap(vector<int> &a, vector<int> &b){
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        
        if(y1-x1 + y2-x2 < -min(x1, x2) + max(y1, y2)) {
            return false;
        }
        return true;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        vector<vector<int>> v;
        
        int ind = addPointInSortedOrder(in, 0, in.size()-1, ne);
        in.insert(in.begin()+ind, ne);
        v.pb(in[0]);
        vector<int> last;
            
        for(int i = 1; i < in.size(); i++){
            last = v[v.size()-1];
            //  if last element and current element overlap, merge them into one
            if(overlap(last, in[i])){   
                v[v.size()-1] = {min(last[0], in[i][0]), max(last[1], in[i][1])};
            }
            else {
                v.pb(in[i]);
            }
        }
            
        return v;
    }
};