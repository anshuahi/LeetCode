/*
LeetCode-POTD: 857. Minimum Cost to Hire K Workers

POTD Link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

Approach
    1. create an array of pair<double, int> of <wage/quality, quality>
    2. Sort the array
    3. use priority queue and sliding window

*/
#define pii pair<double, int>
#define pb push_back

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = wage.size();
        vector<pii> proportions;

        for (int i = 0; i < n; i++)
        {
            proportions.pb({1.0 * wage[i] / quality[i], quality[i]});
        }
        sort(proportions.begin(), proportions.end());
        priority_queue<int> q;
        int i = 0;
        int totalQuality = 0;
        double currPro = 0;
        for (; i < k; i++)
        {
            totalQuality += proportions[i].second;
            q.push(proportions[i].second);
            currPro = proportions[i].first;
        }

        double ans = currPro * totalQuality;
        for (; i < n; i++)
        {
            totalQuality += proportions[i].second - q.top();
            q.pop();
            q.push(proportions[i].second);
            currPro = proportions[i].first;

            ans = min(ans, 1.0 * currPro * totalQuality);
        }

        return ans;
    }
};
