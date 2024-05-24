/*
LeetCode-POTD: 1255. Maximum Score Words Formed by Letters

POTD Link - https://leetcode.com/problems/maximum-score-words-formed-by-letters/description

Approach
1. find all possible subsets of given strings, and choose the maximum score.

*/
class Solution
{
public:
    int solve(int idx, vector<string> &words, vector<int> &freq, vector<int> &score)
    {
        int n = words.size();
        if (idx >= n)
            return 0;
        int sc = 0;
        int i = 0;
        for (i = 0; i < words[idx].size(); i++)
        {
            freq[words[idx][i] - 'a']--;
            sc += score[words[idx][i] - 'a'];
            if (freq[words[idx][i] - 'a'] < 0)
            {
                sc = 0;
                break;
            };
        }
        int ans = 0;
        if (sc)
        {
            ans = max(ans, sc + solve(idx + 1, words, freq, score));
        }
        // backtrack
        for (int j = 0; j <= i && j < words[idx].size(); j++)
        {
            freq[words[idx][j] - 'a']++;
        }
        ans = max(ans, solve(idx + 1, words, freq, score));
        return ans;
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int n = words.size();
        vector<int> freq(26);
        for (auto l : letters)
        {
            freq[l - 'a']++;
        }

        return solve(0, words, freq, score);
    }
};
