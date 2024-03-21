class Solution {
public:
    int singleNumber(vector<int>& v) {
        int x = 0;
        
        long s = 0;
        set<int> st;

        
        for(auto n: v){
            s += n;
            st.insert(n);
        }

        long p = 0;
        for(auto x: st){
            p += x;
        }

        return (3*p-s)/2;
    }
};