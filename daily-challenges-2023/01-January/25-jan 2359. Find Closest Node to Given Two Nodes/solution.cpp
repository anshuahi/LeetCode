class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2){
            return node1;
        }

        int n = edges.size();
        vector<int> first(n, -1), second(n, -1);
        vector<int> vis(n, false);
        queue<int> q;
        q.push(node1);
        first[node1] = 0;
        second[node2] = 0;
        int x = 0;
        while(!q.empty()){
            int f = q.front(); q.pop();
            if(f == -1 || vis[f]){
                continue;
            }
            first[f] = x++;
            vis[f] = true;
            q.push(edges[f]);
        }
       
        q.push(node2);
        x = 0;
        std::fill(vis.begin(), vis.end(), false);
        // for(auto x: vis){
        //     cout << x << " ";
        // }
        while(!q.empty()){
            int f = q.front(); q.pop();
            if(f == -1 || vis[f]){
                continue;
            }
            second[f] = x++;
            vis[f] = true;
            q.push(edges[f]);
        }

        int mn = n, ind = -1;
        for(int i = 0; i < n; i++){
            if(first[i] != -1 && second[i] != -1 && max(first[i], second[i]) < mn){
                ind = i;
                mn = max(first[i], second[i]);
            }
        }
        return ind;
        
    }
};