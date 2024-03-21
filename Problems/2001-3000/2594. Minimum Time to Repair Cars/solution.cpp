#define ll long long int
#define pii pair<int, int>
#define pb push_back

class Solution {
public:
    
    bool check(vector<int>& v, int cars, ll time){
        int repaired = 0;
        for(auto x: v){
            int r = sqrt(time/x);
            repaired += r;
            if(repaired >= cars){
                return true;
            }
        }
        return repaired >= cars;
    }
    
    long long repairCars(vector<int>& v, int cars) {
        sort(v.begin(), v.end());
        int n = v.size();
        ll st = 0, en = 1LL*v[0]*cars*cars;
        while(en-st > 1){
            ll mid = st + (en-st)/2;
            if(check(v, cars, mid)){
                en = mid;
            }
            else {
                st = mid;
            }
        }
        
        if(check(v, cars, st)){
            return st;
        }
        return en;
    }
};