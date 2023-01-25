using namespace std;
#define mp make_pair
#define pii pair<int, int>

bool compare(pii a, pii b){
    return a.first < b.first;
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> v;
        int n = a.size();
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++){
            // if(i >= 1){
            while(i > 0 && i < n && a[i] == a[i-1]){
                i++;
            }
            // }
            int s = i+1, e = n-1;
            while(s < e){
                int p = a[s] + a[e];
                if(p + a[i] == 0){
                    vector<int> v1;
                    v1.push_back(a[i]);
                    v1.push_back(a[s]);
                    v1.push_back(a[e]);
                    // if(!isFound(v, v1)){
                    v.push_back(v1);
                    // }
                    while(s < e && a[s] == a[++s]){
                        // s++;
                    }
                    while(e > s && a[e] == a[--e]){
                        // e--;
                    }
                }
                else if(p + a[i] < 0){
                    s++;
                }
                else {
                    e--;
                }
            }
        }
        return v;
    }
    /* below code for if we need index of all three integers that sums up to zero*/
    // vector<pii> sortedVector(vector<int> a){
    //     vector<pii> v;
    //     for(int i = 0; i < a.size(); i++){
    //         v.push_back(mp(a[i], i));
    //     }
    //     sort(v.begin(), v.end(), compare);
    //     return v;
    // }
    // bool isEqual(vector<int> a, vector<int> b){
    //     int i = 0;
    //     while(i < a.size() && i < b.size()){
    //         if(a[i] != b[i]){
    //             return false;
    //         }
    //         i++;
    //     }
    //     return true;
    // }
    // bool isFound(vector<vector<int>> v, vector<int> v1){
        
    //     int i = 0, n = v.size();
    //     int j = n-1;
        
    //     while(i <= j){
    //         int m = (i+j)/2;
    //         vector<int> x = v[m];
    //         if(v[m][0] == v1[0]){
    //             if(v[m][1] == v1[1]){
    //                 return true;
    //             }
    //             else if(v[m][1] < v1[1]){
    //                 i = m + 1;
    //             }
    //             else {
    //                 j = m - 1;
    //             }
    //         }
    //         else if(v[m][0] < v1[0]){
    //             i = m + 1;
    //         }
    //         else {
    //             j = m - 1;
    //         }
    //     }
        
    //     return false;
    // }
};