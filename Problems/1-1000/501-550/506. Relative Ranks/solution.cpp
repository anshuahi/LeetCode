/*
LeetCode-POTD: 506. Relative Ranks

POTD Link - https://leetcode.com/problems/relative-ranks/description/

*Approach*
    1. sort the array based on value, and also store the index.
    2. assign the respective rank to index
*/
#define pii pair<int, int>
bool comp(pii a, pii b)
{
    return a.first > b.first;
}
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<pii> v;
        int n = score.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            v.push_back({score[i], i});
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < n; i++)
        {
            switch (i)
            {
            case 0:
                ans[v[i].second] = "Gold Medal";
                break;
            case 1:
                ans[v[i].second] = "Silver Medal";
                break;
            case 2:
                ans[v[i].second] = "Bronze Medal";
                break;
            default:
                ans[v[i].second] = to_string(i + 1);
                break;
            }
        }

        return ans;
    }
};
