/*
LeetCode-POTD: 881. Boats to Save People

POTD Link - https://leetcode.com/problems/boats-to-save-people/description/

Approach
   1. sort the array
    2. use two pointers, if first and last person can go on one boat, else send last person on one boat
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int l = 0, r = n-1;
        int ans = 0;
        sort(people.begin(), people.end());
        vector<bool> vis(n);

        while(l <= r){
            int first = people[l], second = people[r];
            if(first + second <= limit){
                ans++;
                l++, r--;
            }
            else {
                ans ++;
                r--;
            }
        }

        return ans;
    }
};
