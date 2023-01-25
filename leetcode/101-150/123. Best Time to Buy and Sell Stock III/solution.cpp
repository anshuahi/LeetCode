class Solution {
public:
    
    
    int maxProfit(vector<int>& p) {
        
        int n = p.size();
        
        if(n <= 1)
            return 0;
        
        vector<int> v;
        
        for(int i = 1; i < n; i++){
            v.push_back(p[i] - p[i-1]);
        }
        
        int ans = 0;
        int sum = 0;
        // int count = 0;
        
        // for(auto v1: v){
        //     cout << v1 << " ";
        // }
        
        vector<int> dp1(v.size(), 0);
        vector<int> dp2(v.size(), 0);
        
        // int sum = 0;
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
            dp1[i] = max(sum, dp1[i]);
            if(i > 0){
                dp1[i] = max(dp1[i], dp1[i-1]);
            }
            if(sum<0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i = v.size()-1; i >=0; i--){
            sum += v[i];
            dp2[i] = max(sum, dp2[i]);
            if(i < v.size()-1){
                dp2[i] = max(dp2[i], dp2[i+1]);
            }
            if(sum<0){
                sum = 0;
            }
        }
        // int 
        int answer = 0;
        for(int i = 0; i < v.size(); i++){
            ans = dp1[i];
            if(i+1 < v.size()){
                ans += dp2[i+1];
            }
            
            answer = max(answer, ans);
        }
            
        
        return answer;
    }
};