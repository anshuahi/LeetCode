#define ll long long int
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        ll p = 1;   // storing current product of the subarray
        ll ans = 0;
        int st = 0; // starting index of subarray
        int n = v.size();
        for(int i = 0; i < v.size(); i++){
            p = p*v[i];
            // while subarray product exceeds k then remove the previous element
            while(p >= k && st <= i){
                // number of subarrays
                ans += (i-st) ;
                p = p/v[st++];
            }
        }
        int x = n-st;
        ans += (x*(x+1))/2;

        return ans;
    }
};
