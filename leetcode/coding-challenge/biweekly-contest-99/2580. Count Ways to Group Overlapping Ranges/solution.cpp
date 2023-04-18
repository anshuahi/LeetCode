// https://leetcode.com/contest/biweekly-contest-99/
// https://leetcode.com/contest/biweekly-contest-99/problems/count-ways-to-group-overlapping-ranges/
#define M 1000000007
#define ll long long int 
class Solution {
public:
    
    bool overlap(vector<int> &a, vector<int> b){
        if(a[0] <= b[0] && b[0] <= a[1]){
            return true;
        }
        if(a[0] <= b[1] && b[1] <= a[1]){
            return true;
        }
        return false;
    }
    
    ll power(int n){
        if(n == 0)
            return 1;
        ll p = power(n/2)%M;
        p = (p*p)%M;
        if(n%2 == 1){
            return (p*2)%M;
        }
        return p%M;
    }
    
    int countWays(vector<vector<int>>& r) {
        int n = r.size();
        sort(r.begin(), r.end());
        int count = 0;
        vector<vector<int>> v;
        v.push_back(r[0]);
        
        for(int i = 1; i < n; i++){
            if(overlap(v.back(), r[i])){
                vector<int> p = v.back();
                v.pop_back();
                v.push_back({min(p[0], r[i][0]), max(p[1], r[i][1])});
            }
            else {
                count++;
                v.clear();
                v.push_back(r[i]);
            }
        }
        
        count++;
        
        return power(count);
        
    }
};