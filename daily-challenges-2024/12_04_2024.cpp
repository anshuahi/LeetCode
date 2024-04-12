/*
LeetCode-POTD: 42. Trapping Rain Water

POTD Link - https://leetcode.com/problems/trapping-rain-water/description/

Approach :
1. find the left and right maximum height for each height
2. calculate the trapped water at a specific height

TimeComplexity: O(N)
SpaceComplexity: O(N)
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);

        // find right-side greater height for each element
        int leftMax = 0;
        for (int i = 0; i < n; i++)
        {
            left[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }

        // find right-side greater height for each element
        int rightMax = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int minHeight = min(left[i], right[i]);
            int water = minHeight - height[i];
            if (water > 0)
                ans += water;
        }

        return ans;
    }
};
