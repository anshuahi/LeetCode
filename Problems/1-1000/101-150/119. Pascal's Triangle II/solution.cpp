class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(1, 1);
        vector<int> row(1, 1);
        // v.push_back(row);
        for(int i = 1; i <= rowIndex; i++) {
            row.clear();
            row.push_back(1);
            for(int j = 1; j < v.size(); j++){
                row.push_back(v[j] + v[j-1]);
            }
            row.push_back(1);
            v = row;
        }
        
        return v;
    }
};