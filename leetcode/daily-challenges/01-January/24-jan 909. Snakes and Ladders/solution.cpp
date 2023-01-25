#define pii pair<int, int>
#define pb push_back

class Solution {
public:

    void printGrid(vector<vector<int>>& b){
        for(auto x: b){
            for(auto a: x){
                cout << a << " "; 
            }
            cout << endl;
        }
    }

    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        reverse(b.begin(), b.end());
        for(int i = 0; i < n; i++){
            if(i%2 == 1){
                reverse(b[i].begin(), b[i].end());
            }
        }
        // converting it to 1-D array.
        vector<int> g(n*n+1, 0);
        int p;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                p = i*n+j +1;
                if(b[i][j] != -1){
                    g[p] = b[i][j];
                }
                else {
                    g[p] = p;
                }
            }
        }

        
        vector<int> steps(n*n+1, INT_MAX);
        vector<bool> vis(n*n+1, false);
        
        steps[0] = steps[1] = 0;
        priority_queue<pii, vector<pii> , greater<pii> > q;

        // BFS
        q.push({0, 1});
        int dest;
        while(!q.empty()){
            pii f1 = q.top();
            q.pop();
            int step = f1.first, pos = f1.second;
            if(pos == n*n){
                return steps[pos];
            }

            for(int i = 1; i <= 6; i++){
                dest = pos+i;
                if(dest <= n*n){
                    dest = g[dest];
                    if(steps[dest] > 1 + step){
                        steps[dest] = 1 + step;
                        q.push({1+ step, dest});
                    }
                }
            }
        }

        return -1;


    }
};