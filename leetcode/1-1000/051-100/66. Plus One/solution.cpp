class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        reverse(v.begin(), v.end());
        
        int carry = 1;
        
        for(int i = 0; i < n && carry; i++){
            int x = v[i] + carry;
            v[i] = x%10;
            carry = x/10;
        }
        
        if(carry){
            v.push_back(1);
        }
        reverse(v.begin(), v.end());
        
        return v;
        
    }
};