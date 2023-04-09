class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        // int i = 0;
        int f = v.size();
        if(f == 0){
            return n <= 0;
        }
        if(f == 1){
            if(v[0] == 0){
                n--;
            }
            return n <= 0;
        }

        for(int i = 0; i < f; i++){
            if(v[i] == 1){
                continue;
            }
            if(i == 0){
                if(v[i+1] == 0){
                    v[i] = 1;
                    n--;
                }
            }
            else if(i == f-1){
                if(v[i-1] == 0){
                    v[i] = 1;
                    n--;
                }
            }
            else {
                if(v[i+1] == 0 && v[i-1] == 0){
                    v[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};