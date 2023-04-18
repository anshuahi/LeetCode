#define pii pair<int, int>
#define pb push_back
class Graph {
public:
    vector<vector<pii>> gr;
    int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        gr.resize(n);
        for(auto ed: edges){
            gr[ed[0]].pb({ed[1], ed[2]});
        }
    }
    
    void addEdge(vector<int> ed) {
        gr[ed[0]].pb({ed[1], ed[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, node1});
        vector<bool> vis(nodes);
        while(!q.empty()){
            pii p = q.top(); q.pop();
            int dist = p.first, node = p.second;
            if(node == node2)
                return dist;
            if(vis[node])
                continue;
            vis[node] = true;
            
            for(auto x: gr[node]){
                if(!vis[x.first])
                    q.push({x.second+ dist, x.first});
            }
            
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */