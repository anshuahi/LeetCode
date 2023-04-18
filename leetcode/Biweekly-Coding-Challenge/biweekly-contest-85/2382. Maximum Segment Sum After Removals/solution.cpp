// Genius Solution (out of the box thinking)
#define ll long long
#define pb push_back
class Solution {
public:

    void Union(int i, int j, vector<int> &parent, vector<ll> &sum){
        int x = find(i, parent);
        int y = find(j, parent);
        if(x == y){
            return;
        }
        parent[x] = y;
        sum[y] += sum[x];
    }

    int find(int i, vector<int> &parent){
        if(parent[i] == i){
            return i;
        }
        int x = find(parent[i], parent);
        parent[i] = x;
        return x;
    }

    vector<long long> maximumSegmentSum(vector<int>& v, vector<int>& removeQueries) {
        int n = v.size();
        vector<int> parent(n, -1);
        vector<ll> sum(n, 0), segment(1, 0);
        ll ans = 0;
        for(int k = n-1; k >= 0; k--){
            int i = removeQueries[k];
            parent[i] = i;
            sum[i] = v[i];
            int j = i+1;
            if(0 <= j && j < n && parent[j] != -1){
                Union(i, j, parent, sum);
            }
            j = i-1;
            if(0 <= j && j < n && parent[j] != -1){
                Union(i, j, parent, sum);
            }
            int x = find(i, parent);
            ans = max(sum[x], ans);
            segment.pb(ans);
        }
        segment.pop_back();
        reverse(segment.begin(), segment.end());
        return segment;
    }
};