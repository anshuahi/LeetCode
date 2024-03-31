/*
LeetCode-POTD: 2444. Count Subarrays With Fixed Bounds

POTD Link - https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/31_03_2024.cpp

*Approach* :
    1. find the index of minK and maxK, and keep track of lastMinK and lastMaxK.
    2. add the window size to answer, 

*/

#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        ll count = 0;
        int n = v.size();
        int left = -1, lastMin = -1, lastMax = -1;

        for(int i = 0;i < n; i++){
            if(minK <= v[i] && v[i] <= maxK){
                lastMin = v[i] == minK? i: lastMin;
                lastMax = v[i] == maxK? i: lastMax;

                count += max(0, min(lastMin, lastMax)-left);
            }
            else {
                left = i;
                lastMin = -1, lastMax = -1;
            }
        }

        return count;
    }
};
