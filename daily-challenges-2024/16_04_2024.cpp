/*
GeeksForGeeks-POTD: Minimize the Difference


POTD Link: https://www.geeksforgeeks.org/problems/minimize-the-difference/1

Approach
    1. save the prefix min and max, and suffix min and max.
    2. remove the subarray of size k and calculate min and max from above arrays
    3. store the diff to ans.

TimeComplexity: O(N)
SpaceComplexity: O(N)

*/

class Solution
{
public:
    void printArray(vector<int> &v)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    int minimizeDifference(int n, int k, vector<int> &arr)
    {
        vector<int> minSt(n), minEn(n), maxSt(n), maxEn(n);
        int mn = arr[0];
        int mx = arr[0];
        for (int i = 0; i < n; i++)
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
            minSt[i] = mn;
            maxSt[i] = mx;
        }
        mn = arr[n - 1];
        mx = arr[n - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
            minEn[i] = mn;
            maxEn[i] = mx;
        }

        int ans = abs(minEn[k] - maxEn[k]);
        for (int i = 0; i < n; i++)
        {
            if (i + k + 1 < n)
            {
                int a = min(minSt[i], minEn[i + k + 1]);
                int b = max(maxSt[i], maxEn[i + k + 1]);
                ans = min(ans, abs(a - b));
            }
        }
        ans = min(ans, abs(minSt[n - k - 1] - maxSt[n - k - 1]));
        return ans;
    }
};
