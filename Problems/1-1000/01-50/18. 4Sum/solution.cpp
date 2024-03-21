#define pii pair<int, int>
class Solution {
public:
    
    vector<vector<int>> searchTarget(vector<int> v, int s, long t){
        int e = v.size()-1;
        vector<vector<int>> x;
        
        while(s < e){
            long val = v[s] + v[e];
            if(val == t){
                x.push_back({v[s], v[e]});
                int z = v[s];
                while(s < e){
                    s++;
                    if(s == e)
                        break;
                    if(v[s] != z)
                        break;
                }
            }
            else if(val < t){
                s++;
            }
            else {
                e--;
            }
        }
        
        return x;
    }
    
    
    vector<vector<int>> fourSum(vector<int>& v, long t) {
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            if(i > 0 && v[i] == v[i-1]){
                continue;
            }
            for(int j = i+1; j < n; j++){
                if(j > i+1 && v[j] == v[j-1]){
                    continue;
                }
                else {
                    vector<vector<int>> z = searchTarget(v, j+1, t-v[i]-v[j]);
                    for(auto q: z){
                        ans.push_back({v[i], v[j], q[0], q[1]});
                    }
                }
            }
            
        }
        
        return ans;
    }
};