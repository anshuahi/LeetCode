class Solution {
public:

    bool check(vector<int> &p, int mid, int m){
        int curr = p[0];
        int count = 1;
        for(int i = 1; i < p.size(); i++){
            if(p[i] - curr>= mid){
                count++;
                curr = p[i];
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& p, int m) {
        int n = p.size();
        sort(p.begin(), p.end());
        int lo = 1, hi = p[n-1]-p[0];
        while(hi -lo > 1){
            int mid = (hi+lo)/2;
            if(check(p, mid, m)){
                lo = mid;
            }
            else{
                hi = mid-1;
            }
        }
        if(check(p, hi, m))
            return hi;
        return lo;
    }
};