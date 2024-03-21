class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        sort(v.begin(), v.end());
        int ex = 1;
        int i = 0;
        int n = v.size();
        while(i < n && v[i] <= 0){
            i++;
        }
        
        for(; i < n; i++){
            if(v[i] == ex){
                ex++;
            }
        }
        return ex;
    }
};