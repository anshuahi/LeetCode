class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> right(n, -1), left(n, -1);
        stack<int> s;
        
        // find next greater element
        for(int i = 0; i < n; i++){
            if(s.empty()){
                s.push(i);
            }
            else {
                if(h[s.top()] >= h[i]){
                    right[i] = h[s.top()];
                }
                else {
                    s.pop();
                    s.push(i);
                }
            }
        }
        
        while(!s.empty()) {
            s.pop();
        }
        // find previous greater element
        for(int i = n-1; i >= 0; i--) {
            if(s.empty()){
                s.push(i);
            }
            else {
                if(h[s.top()] >= h[i]){
                    left[i] = h[s.top()];
                }
                else {
                    s.pop();
                    s.push(i);
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(left[i] != -1 && right[i] != -1){
                sum += min(left[i], right[i]) - h[i];
            }
        }

        
        return sum;
    }
};