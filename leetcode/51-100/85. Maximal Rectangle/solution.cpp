class Solution {
public:
    
    int largestRectangleArea(vector<int>& v) {
        
        int n = v.size();
        
        vector<int> l(n, -1);
        vector<int> r(n, n);
        
        stack<int> s;
        for(int i = 0; i < n; i ++){
            if(s.empty()){
                s.push(i);
            }
            else {
                while(!s.empty() && v[i] < v[s.top()]){
                    r[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i = n-1; i >= 0; i --){
            if(s.empty()){
                s.push(i);
            }
            else {
                while(!s.empty() && v[i] < v[s.top()]){
                    l[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
        }
                
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans = max(ans, (r[i]-l[i]-1)*v[i]);
        }       
        
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> v(m, 0);
        
        ans = largestRectangleArea(v);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == '0'){
                    v[j] = 0;
                }
                else {
                    v[j] ++;
                }
                
                // cout << v[j] << " ";
            }
            // cout << endl;
            ans = max(ans, largestRectangleArea(v));
        }
        
        return ans;
    }
};