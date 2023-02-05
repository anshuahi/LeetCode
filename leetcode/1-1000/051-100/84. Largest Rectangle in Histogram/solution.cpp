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
        
        while(!s.empty()){
            s.pop();
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans = max(ans, (r[i]-l[i]-1)*v[i]);
        }
        
        
        
        return ans;
    }
};