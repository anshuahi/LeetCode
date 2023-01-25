class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1){
            return 0;
        }
        
        int mx = 0;
        int count = 0;
        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else {
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int y = st.top();
                    if(s[y] == '('){    // if found valid
                        st.pop();
                        int x;
                        if(st.empty()){
                            x = -1;
                        }
                        else {
                            x = st.top();
                        }
                        mx = max(mx, i - x);
                    }
                    else {
                        st.push(i);
                    }
                }
            }
        }
        return mx;
    }
};