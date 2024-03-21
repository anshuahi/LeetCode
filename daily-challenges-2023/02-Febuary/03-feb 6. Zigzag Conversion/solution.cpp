class Solution {
public:
    string convert(string s, int k) {
        int n = s.length();
        string p = "";
        if(k == 1){
            return s;
        }
        for(int i = 0; i < k; i++){
            int j = i;
            while(j < n){
                if(i == 0 || i == k-1){
                    p += s[j];
                    j += 2*(k-1);
                }
                else {
                    p += s[j];
                    j += 2*(k-1-i);
                    if(j < n){
                        p += s[j];
                        j += 2*i;
                    }
                }
            }
        }
        return p;
    }
};