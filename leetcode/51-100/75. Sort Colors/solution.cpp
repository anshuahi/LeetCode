class Solution {
public:
    void sortColors(vector<int>& v) {
        int red = 0, wh = 0, bl = v.size();
        for(int i : v){
            if(i==0){
                red++;
                wh++;
                bl++;
            }
            if(i == 1){
                wh++;
                bl++;
            }
        }
        int i = 0;
        while(i < v.size() && i < red){
            v[i++] = 0;
        }
        while(i < v.size() && i < wh){
            v[i++] = 1;
        }
        while(i < v.size()){
            v[i++] = 2;
        }
    }
};