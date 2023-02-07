class Solution {
public:
    int totalFruit(vector<int>& v) {
        int fi = 0, si = 0;
        int fe = 0, se = 0;
        int f = v[0], s;
        int i = 1;
        int n = v.size();
        int ans = 0;
        while(i < n){
            if(v[i] != f){
                break;
            }
            i++;
        }
        if(i >= n-1){
            return n;
        }
        ans = i+1;
        s = v[i];
        si = i;
        se = i;
            // ans = max(ans, abs(max(fe, se) - min(fi, si)+1));
        // int ans = 0;
        for(int j = i+1; j < n; j++){
            if(v[j] == s){
                se = j;
            }
            else if(v[j] == f){
                fe = j;
            }
            else {
                if(fe < se){
                    si = max(si, fe+1);
                    fi = fe = j;
                    f = v[j];
                }
                else {
                    fi = max(fi, se+1);
                    si = se = j;
                    s = v[j];
                }
            }
            ans = max(ans, abs(max(fe, se) - min(fi, si)+1));
            // cout << f << " -> " << fi << " " << fe << endl;
            // cout << s << " -> " << si << " " << se << endl;
            // cout << abs(max(fe, se) - min(fi, si)+1) << endl;
        }
        ans = max(ans, abs(max(fe, se) - min(fi, si)+1));
        return ans;

    }
};