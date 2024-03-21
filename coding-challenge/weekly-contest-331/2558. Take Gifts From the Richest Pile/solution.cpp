#define ll long long int 
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ll ans = 0;
        priority_queue<int> q;
        for(auto g: gifts){
            q.push(g);
        }
        while(k--){
            int t = sqrt(q.top());
            q.pop();
            q.push(t);
        }
        
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        
        return ans;
    }
};