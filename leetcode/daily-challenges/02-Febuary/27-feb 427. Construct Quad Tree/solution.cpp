/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    bool isAllSame(vector<vector<int>>& grid){
        int n = grid.size();
        int sum = 0;
        for(auto x: grid){
            for(auto y: x){
                sum += y;
            }
        }
        return sum == 0 || sum == n*n;
    }

    Node* construct(vector<vector<int>>& grid) {
        bool val = grid[0][0] == 1;
        if(isAllSame(grid)){
            return new Node(val, true);
        }
        int n = grid.size();
        vector<vector<int>> tl, tr, bl, br;
        for(int i = 0; i < n/2; i++){
            vector<int> v;
            for(int j = 0; j < n/2; j++){
                v.push_back(grid[i][j]);
            }
            tl.push_back(v);
        }
        
        for(int i = n/2; i < n; i++){
            vector<int> v;
            for(int j = 0; j < n/2; j++){
                v.push_back(grid[i][j]);
            }
            bl.push_back(v);
        }
        for(int i = 0; i < n/2; i++){
            vector<int> v;
            for(int j = n/2; j < n; j++){
                v.push_back(grid[i][j]);
            }
            tr.push_back(v);
        }
        
        for(int i = n/2; i < n; i++){
            vector<int> v;
            for(int j = n/2; j < n; j++){
                v.push_back(grid[i][j]);
            }
            br.push_back(v);
        }
        return new Node(1,false, construct(tl), construct(tr), construct(bl), construct(br));
        // return new Node(val, true);
        // Genius solution
    }
};
