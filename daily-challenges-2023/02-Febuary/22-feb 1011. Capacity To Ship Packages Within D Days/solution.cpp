#define ll long long int
#define pb push_back

class Solution {
public:

    bool check(int m, vector<int>& weights, int k){
        int p = 0;
        int x = 0;
        for(auto w: weights){
            if(w > m){
                return false;
            }
            x += w;
            if(x > m){
                p++;
                x = w;
            }
        }
        if(x){
            p++;
        }
        return p <= k;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        ll sum = 0;
        for(auto w: weights){
            sum += w;
        }
        int st = 1, en = sum;
        if(days == 1){
            return sum;
        }
        while(en - st > 1){
            // cout << st << " " << en << " ->\t ";
            int mid = (st+en)/2;
            bool b = check(mid, weights, days);
            // cout << mid << " " << (b? "true" : "false") << endl;
            if(b){
                en = mid;
            }
            else {
                st = mid;
            }
        }
        if(check(st, weights, days)){
            return st;
        }

        return en;
    }
};
// Genius