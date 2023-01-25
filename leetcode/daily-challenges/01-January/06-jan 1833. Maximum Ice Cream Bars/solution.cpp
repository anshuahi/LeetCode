class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        int n = costs.size();
        for(int i = 0; i < n; i++){
            sum += costs[i];
            if(sum > coins){
                return i;
            }
        }
        return n;
    }
};