/*
LeetCode-POTD: 402. Remove K Digits

POTD Link - https://leetcode.com/problems/remove-k-digits/description/

Approach :
1. use stack and remove the elements from the stack if the top element is greater than the current

TimeComplexity: O(N)
SpaceComplexity: O(N)

*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (auto c : num)
        {
            while (!st.empty() && k && st.top() > c)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (!st.empty() && k)
        {
            st.pop();
            k--;
        }
        num = "";
        while (!st.empty())
        {
            num += st.top();
            st.pop();
        }
        // remove appended zeros
        while (num.size() && num.back() == '0')
        {
            num.pop_back();
        }

        reverse(num.begin(), num.end());
        return (num == "") ? "0" : num;
    }
};