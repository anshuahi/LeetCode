#define pb push_back
#define pii pair<int, int>

class Solution {
public:

    bool isIntersect(pii a, pii b){
        if(a.first <= b.first && b.first <= a.second){
            return true;
        }
        if(a.first <= b.second && b.second <= a.second){
            return true;
        }
        return false;
    }

    pii common(pii a, pii b){
        return {max(a.first, b.first), min(a.second, b.second)};
    }

    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end());
        vector<pii> v;

        v.pb({p[0][0], p[0][1]});

        for(int i = 1; i < p.size(); i++){
            if(isIntersect(v.back(), {p[i][0], p[i][1]})){
                pii x = v.back();
                v.pop_back();
                v.pb(common(x, {p[i][0], p[i][1]}));
            }
            else {
                v.pb({p[i][0], p[i][1]});
            }
        }
        return v.size();
    }
};