class Solution {
public:
    string gcdOfStrings(string a, string b) {
        if(a == b){
            return a;
        }
        int n = a.size(), m = b.size();
        if(n == m){
            return "";
        }
        if(n < m){
            return gcdOfStrings(b, a);
        }
        // n > m
        if(a.substr(0, m) != b){
            return "";
        }
        return gcdOfStrings(b, a.substr(m));
    }
};

// a b
// b, a-b