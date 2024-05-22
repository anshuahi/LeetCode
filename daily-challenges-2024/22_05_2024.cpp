/*
LeetCode-POTD: 131. Palindrome Partitioning

POTD Link - https://leetcode.com/problems/palindrome-partitioning/description/

Approach
    1. find all possible palindrome substring, and iterate through all index

*/
#define pb push_back

class Solution
{
public:
    vector<vector<string>> parti(string s, vector<vector<int>> &g, int i)
    {
        if (i == s.size())
        {
            return {{}};
        }
        vector<vector<string>> ans, p;
        string a;
        for (auto x : g[i])
        {
            p = parti(s, g, x + 1);
            a = s.substr(i, x - i + 1);
            for (auto p1 : p)
            {
                p1.insert(p1.begin(), a);
                ans.pb(p1);
            }
        }

        return ans;
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {
            g[i].pb(i);
            // odd length palindrome
            int j = 1, k;
            while (i - j >= 0 && i + j < n)
            {
                if (s[i - j] == s[i + j])
                {
                    g[i - j].pb(i + j);
                }
                else
                {
                    break;
                }
                j++;
            }
            // even length palindrome
            j = i, k = i + 1;
            while (j >= 0 && k < n)
            {
                if (s[j] == s[k])
                {
                    g[j].pb(k);
                }
                else
                {
                    break;
                }
                j--, k++;
            }
        }

        vector<vector<string>> ans = parti(s, g, 0);
        return ans;
    }
};
