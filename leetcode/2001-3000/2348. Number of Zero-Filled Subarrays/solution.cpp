#define ll long long int
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
        ll ans = 0;
        int count = 0;
        for(int x: v){
            if(x == 0){
                count++;
            }
            else {
                ans += 1LL*count*(count+1)/2;
                count = 0;
            }
        }
        ans += 1LL*count*(count+1)/2;
        return ans;
    }
};