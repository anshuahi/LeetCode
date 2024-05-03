/*
LeetCode-POTD: 165. Compare Version Numbers

POTD Link - https://leetcode.com/problems/compare-version-numbers/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/03_05_2024.cpp

Approach
    1. Split each version number into an integer array
    2. compare the 2 arrays
*/
class Solution {
public:
    vector<int> convert(string &s){
        vector<int> ans;
        string p = "";
        for(auto x: s){
            if(x == '.'){
                ans.push_back(stoi(p));
                p = "";
            }
            else {
                p += x;
            }
        }
        ans.push_back(stoi(p));
        return ans;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = convert(version1);
        vector<int> v2 = convert(version2);
        int m = v1.size(), n = v2.size();
        int i;
        for(i = 0; i < n && i < m; i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        while(i < m){
            if(v1[i++]) return 1;
        }
        while(i < n){
            if(v2[i++]) return -1;
        }

        return 0;
    }
};
