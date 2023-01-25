class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();
        int s = 0, e = n-1;
        
        while(s < e) {
            int x = min(height[e], height[s]);
            ans = max(ans, x * (e-s));
            if(height[e] > height[s]){
                s++;
            }
            else
                e--;
        }
        
        return ans;
    }
};