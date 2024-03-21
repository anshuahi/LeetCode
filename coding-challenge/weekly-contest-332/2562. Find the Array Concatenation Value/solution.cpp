#define ll long long 
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& v) {
        int n = v.size();
        ll ans = 0;
        string s;
        for(int i = 0; i < n/2; i++){
            s = to_string(v[i])+to_string(v[n-i-1]);
            ans += stoi(s);
        }
        if(n%2 == 1){
            ans += v[n/2];
        }
        return ans;
    }
};