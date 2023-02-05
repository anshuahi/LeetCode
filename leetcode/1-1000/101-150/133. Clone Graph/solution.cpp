/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#define pb push_back

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        int w = node->val;
        vector<Node*> v(101), u;
        vector<vector<int>> gr(101);
        vector<bool> vis(101, false);
        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* f = q.front();q.pop();
            if(!f || vis[f->val]){
                continue;
            }
            vis[f->val] = true;
            for(auto x: f->neighbors){
                gr[f->val].pb(x->val);
                q.push(x);
            }
        }

        for(int i = 0; i <= 100; i++){
            if(vis[i]){
                v[i] = new Node(i);
            }
            else {
                v[i] = NULL;
            }
        }

        for(int i = 0; i <= 100; i++){
            if(vis[i]){
                u.clear();
                for(auto x: gr[i]){
                    u.pb(v[x]);
                }
                v[i]->neighbors = u;
            }
        }
        

        return v[w];

    }
};












