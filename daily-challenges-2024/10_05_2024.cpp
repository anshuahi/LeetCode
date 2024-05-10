/*
LeetCode-POTD: 786. K-th Smallest Prime Fraction

POTD Link - https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

*/
class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        int n = arr.size();
        double left = 0, right = 2;

        while (left < right)
        {
            double mid = (left + right) / 2;

            double maxFraction = 0.0;
            int count = 0, numerator = 0, denominator = 0;
            int j = 1;

            for (int i = 0; i < n - 1; i++)
            {
                while (j < n && arr[i] * 1.0 / arr[j] >= mid)
                {
                    j++;
                }
                count += (n - j);
                if (n == j)
                    break;

                double fraction = (arr[i] * 1.0) / arr[j];

                if (fraction > maxFraction)
                {
                    numerator = i;
                    denominator = j;
                    maxFraction = fraction;
                }
            }
            cout << mid << " " << count << endl;
            if (count == k)
            {
                return {arr[numerator], arr[denominator]};
            }
            else if (count > k)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return {};
    }
};
