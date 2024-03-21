class Solution {
public:
    int partitionString(string s) {
        vector<int> v(26, -1);
        int ans = 0;
        int st = -1;
        for(int i = 0; i < s.size(); i++){
            int c = s[i]-'a';
            if(v[c] >= st){
                ans ++;
                v[c] = i;
                st = i;
            }
            else {
                v[c] = i;
            }
        }
        return ans;
    }
};