// GENIUS Solution
#define pii pair<int, int>
class TreeAncestor {
public:
    vector<vector<int>> parent;
    TreeAncestor(int n, vector<int>& p) {
        int h = ceil(1.0*log(n+1)/log(2))+1;
        parent.resize(h+2, vector<int>(n, -1));
        parent[1] = p;
        for(int j = 2; j <= h+1; j++){
            for(int i = 0; i < n; i++){
                int par = parent[j-1][i];
                if(par == -1)
                    parent[j][i] = -1;
                else {
                    parent[j][i] = parent[j-1][par];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int p = 1;
        while(k > 0 && node != -1){
            if(k%2 == 1){
                node = parent[p][node];
            }
            p++;
            k = k/2;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */