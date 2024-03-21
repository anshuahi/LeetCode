class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        stack<int> s;
        int n = v.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < 2*n; i++){
            if(s.empty()){
                s.push(i);
            }
            else {
                while(!s.empty() && v[s.top()%n] < v[i%n]){
                    ans[s.top()%n] = v[i%n];
                    s.pop();
                }
                s.push(i);
            }
        }
        return ans;
    }
};