class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
    
        char x,y;
        for(int i=0;i<s.length();i++)
        {
            if(st.size()==0)
                st.push(s[i]);
            else
            {
                x = s[i];
                y = st.top();
                if(x == '(' || x=='{' || x=='[')
                    st.push(x);

                else
                {
                    if(x=='}')
                    {
                        if(y=='{') st.pop();
                        else  return false;      
                    }
                    if(x==']')
                    {
                        if(y=='[') st.pop();
                        else return false;    
                    }
                    if(x==')')
                    {
                        if(y=='(') st.pop();
                        else return false;     
                    }
                }
            }
        }
        return st.size()==0;
        
    }
};