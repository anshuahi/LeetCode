#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        ll count = 0;
        int n = v.size();
        int left = -1, lastMin = -1, lastMax = -1;

        for(int i = 0;i < n; i++){
            if(minK <= v[i] && v[i] <= maxK){
                lastMin = v[i] == minK? i: lastMin;
                lastMax = v[i] == maxK? i: lastMax;

                count += max(0, min(lastMin, lastMax)-left);
            }
            else {
                left = i;
                lastMin = -1, lastMax = -1;
            }
        }

        return count;
    }
};