class Solution {
public:

    bool check(vector<int>& piles, int k, int h) {
        int ans = 0;
        for(auto p: piles){
            ans += ceil(p*1.0/k);
            if(ans > h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int st = 1, en = INT_MAX;
        while(en - st > 1){
            int mid = st + (en-st)/2;
            if(check(piles, mid, h)){
                en = mid;
            }
            else {
                st = mid;
            }
        }
        if(check(piles, st, h)){
            return st;
        }
        return en;
    }
};