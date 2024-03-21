class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<long> s;
        for(string t: tokens) {
            if(t == "+"){
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a+b);
            }
            else if(t == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b-a);
            }
            else if(t == "*") {
                long a = s.top(); s.pop();
                long b = s.top(); s.pop();
                s.push(a*b);                
            }
            else if(t == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                // cout << a<< " " << b << " -> " << a/b << endl;
                s.push(b/a);                
            }
            else {
                // s.push
                s.push(stoi(t));
            }
        }
        return s.top();
    }
};