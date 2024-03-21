class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        int i = 0, j = 0;
        while(i < n && j < n){
            if(!s.empty() && s.top() == popped[j]){
                s.pop();
                j++;
            }
            else {
                s.push(pushed[i]);
                i++;
            }
        }
        while(!s.empty() && popped[j] == s.top()){
            s.pop();
            j++;
        }
        return s.empty();
    }
};