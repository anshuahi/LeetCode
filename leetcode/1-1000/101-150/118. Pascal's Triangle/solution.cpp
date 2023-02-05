class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> row(1, 1);
        v.push_back(row);
        for(int i = 1; i < numRows; i++) {
            row.clear();
            row.push_back(1);
            for(int j = 1; j < v[i-1].size(); j++){
                row.push_back(v[i-1][j] + v[i-1][j-1]);
            }
            row.push_back(1);
            v.push_back(row);
        }
        
        return v;
    }
};