/*
LeetCode-POTD: 678. Valid Parenthesis String

POTD Link - https://leetcode.com/problems/valid-parenthesis-string/description/

Approach :
1. initialize open and close with zero and iterate the string.
2. if '(' increment open and close
3. if ')' decrement open and close
4. if '*' increment open and decrement close
5. if open becomes negative, make it zero,
6. if close becomes negative return false.
7. at last, check if open is equal to zero
TimeComplexity: O(N)
SpaceComplexity: O(1)

*/

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();
        int open = 0, close = 0;
        for (auto c : s)
        {
            c == '(' ? open++ : open--;
            c != ')' ? close++ : close--;
            open = max(open, 0);
            if (close < 0)
                return false;
        }

        return open == 0;
    }
};