class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0;
        int ind = 0;
        int a = 0, b = 0;
        for(auto g: gas){
            a += g;
        }
        for(auto g: cost){
            b += g;
        }
        if(b > a)
            return -1;
        int n = gas.size();
        vector<bool> c(n, false);

        for(int i= 0; i < n; i++){
            s += gas[i] - cost[(i)%n];
            if(s < 0){
                s = 0;
                ind = i+1;
            }
        }
        
        return ind;
    }
};
