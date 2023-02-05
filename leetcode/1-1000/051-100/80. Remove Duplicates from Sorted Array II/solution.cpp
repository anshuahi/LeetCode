#define pb push_back

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int count = 1;
        vector<int> v;
        v.pb(a[0]);

        for(int i = 1; i < a.size(); i++){
            if(a[i] == a[i-1]){
                count++;
                if(count <= 2){
                    v.pb(a[i]);
                }
            }
            else {
                v.pb(a[i]);
                count = 1;
            }
        }

        for(int i = 0; i < v.size(); i++){
            a[i] = v[i];
        }

        return v.size();

    }
};