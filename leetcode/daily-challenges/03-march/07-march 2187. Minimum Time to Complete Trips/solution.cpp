#define pii pair<int, int>
#define ll long long int
class Solution {
public:

    bool check(vector<int> &v, ll m, int t){
        ll ans = 0;
        for(auto x: v){
            ans += (m/x);
        }
        return ans >= t;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        int ans = 0;
        ll st = time[0], en = 1LL*totalTrips*time[0];
        while(st < en-1){
            ll mid = (st+en)/2;
            if(check(time, mid, totalTrips)){
                en = mid;
            }
            else {
                st = mid;
            }
        }
        if(check(time, st, totalTrips))
            return st;
        return en;
    }
};