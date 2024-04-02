/*
LeetCode-POTD: 205. Isomorphic Strings

POTD Link - https://leetcode.com/problems/isomorphic-strings/description

Approach :     
   1. if both chars are not in map, map them to each other.
2. if any one them is not present in map, return false
3. if both are present in map, and are not mapped with each other, return false

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1, mp2;
        for(int i = 0; i < s.size(); i++){
            // if both chars are not in map, store in the maps
            if(mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            // if one of the chars are in map, return false
            else if(mp1.find(s[i]) == mp1.end() || mp2.find(t[i]) == mp2.end()){
                return false;
                
            }
            // else check if they mapped to each other
            else if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i]){
                return false;
            }
        }

        return true;
    }
};
