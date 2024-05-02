/*
LeetCode-POTD: 1915. Number of Wonderful Substrings

POTD Link - https://leetcode.com/problems/number-of-wonderful-substrings/description/

GitHub Solution Link- https://github.com/anshuahi/LeetCode/blob/main/daily-challenges-2024/30_04_2024.cpp
Approach
    1. Create a frequency array. initialize freq[0] = 1
    2. Initialize a mask int variable to 0.
    3. For each character in the word, flip the corresponding bit in the mask.
    4. Add the frequency of the mask to the answer.
    5. Increment the value associated with the key mask by one.
    6. Iterate through each possible character that appears an odd number of times, and add the frequency of mask ^ (1 << i), where ^ is the XOR function.
    7. Return the result when all letters are processed.
*/

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        int n = word.size();
        vector<int> freq(1024);

        freq[0] = 1;
        int mask = 0;
        long long ans = 0;
        for (auto ch : word)
        {
            int bit = ch - 'a';
            mask ^= (1 << bit);
            ans += freq[mask];
            freq[mask]++;
            for (int i = 0; i < 10; i++)
            {
                ans += freq[mask ^ (1 << i)];
            }
        }

        return ans;
    }
};
