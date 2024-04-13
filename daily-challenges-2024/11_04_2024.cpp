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
public
    String removeKdigits(String num, int k)
    {
        Stack<Character> st = new Stack<>();
        for (char digit : num.toCharArray())
        {
            while (!st.isEmpty() && k > 0 && Character.compare(st.peek(), digit) > 0)
            {
                st.pop();
                k--;
            }
            if (st.isEmpty() && Character.compare('0', digit) == 0)
            {
                continue;
            }
            st.add(digit);
        }
        while (!st.isEmpty() && k > 0)
        {
            st.pop();
            k--;
        }

        StringBuilder result = new StringBuilder();
        while (!st.isEmpty())
        {
            result.append(st.pop());
        }
        result.reverse();
        if (result.length() == 0)
            result.append("0");
        return result.toString();
    }
}
