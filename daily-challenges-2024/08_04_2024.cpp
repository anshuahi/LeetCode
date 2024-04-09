/*LeetCode-POTD: 1700. Number of Students Unable to Eat Lunch

POTD Link - https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

Approach :
1. Count the number of students preferring each type of sandwich.
2. Serve sandwiches to students based on their preferences.
3. Keep track of remaining sandwiches to be served.
4. Return the count of remaining sandwiches,

TimeComplexity: O(N)
SpaceComplexity: O(1)

*/

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        vector<int> count(2);
        for (auto st : students)
        {
            count[st]++;
        }

        int rem = sandwiches.size();
        for (int sandwich : sandwiches)
        {
            if (count[sandwich] == 0)
                break;
            if (rem-- == 0)
                break;
            count[sandwich]--;
        }
        return rem;
    }
};
