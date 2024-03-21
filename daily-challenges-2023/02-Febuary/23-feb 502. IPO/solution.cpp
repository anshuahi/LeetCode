#define ll long long int
#define pii pair<int, int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int profit = 0;
        priority_queue<pii> pr;
        priority_queue<pii, vector<pii>, greater<pii>> cp;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            cp.push({capital[i], profits[i]});
        }
        while(k > 0){
            k--;
            while(!cp.empty() && cp.top().first <= w){
                pr.push({cp.top().second, cp.top().first});
                cp.pop();
            }
            if(!pr.empty()){
                w += pr.top().first;
                pr.pop();
            }
        }

        return w;
    }
};