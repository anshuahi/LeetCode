/*
LeetCode-POTD: 85. Maximal Rectangle

POTD Link - https://leetcode.com/problems/maximal-rectangle/description/

Approach :
1. make a height array of each row,
2. find the maximum histogram area for each height

TimeComplexity: O(N)
SpaceComplexity: O(N)

*/

class Solution
{
public:
    int maximumHistogramArea(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && height[st.top()] > height[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && height[st.top()] > height[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int area = height[i] * (right[i] - left[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            }
            maxArea = max(maxArea, maximumHistogramArea(height));
        }
        return maxArea;
    }
};
