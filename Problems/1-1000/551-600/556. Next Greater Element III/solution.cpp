#define pb push_back
#define ll long long int
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while(n > 0){
            int d = n%10;
            v.pb(d);
            n = n/10;
        }
        bool b = true;
        for(int i = 1; i < v.size(); i++){
            if(v[i] < v[i-1]){
                b = false;
            }
        }
        if(b)
            return -1;
        reverse(v.begin(), v.end());
        next_permutation(v.begin(), v.end());
        ll x = 0;
        for(auto a: v){
            x = x*10+a;
        }
        // cout << x<< " \n" << pow(2, 31);
        if(x >= pow(2, 31))
            return -1;
        return x;
    }
};