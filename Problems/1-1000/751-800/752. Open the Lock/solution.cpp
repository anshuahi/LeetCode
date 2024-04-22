/*
LeetCode-POTD: 752. Open the Lock

POTD Link - https://leetcode.com/problems/open-the-lock/description/

Approach :
    1. start from "0000"
    2. traverse all possible combination
    3. store the turn for each combination in an array
*/
#define pii pair<int, string>

class Solution
{
public:
    set<string> st;
    char nextChar(char a)
    {
        return a == '9' ? '0' : ++a;
    }
    char prevChar(char a)
    {
        return a == '0' ? '9' : --a;
    }

    int openLock(vector<string> &deadends, string target)
    {
        for (auto deadend : deadends)
        {
            st.insert(deadend);
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, "0000"});
        vector<int> dp(10000, -1);
        while (!q.empty())
        {
            pii p = q.top();
            q.pop();
            int turn = p.first;
            string seq = p.second;
            if (seq == target)
                return turn;
            if (st.find(seq) != st.end() || dp[stoi(seq)] != -1)
                continue;
            dp[stoi(seq)] = turn;
            for (int i = 0; i < 4; i++)
            {
                string seq1 = seq;
                seq1[i] = nextChar(seq[i]);
                q.push({turn + 1, seq1});
                seq1[i] = prevChar(seq[i]);
                q.push({turn + 1, seq1});
            }
        }

        return -1;
    }
};
