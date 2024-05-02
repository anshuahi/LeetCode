/*
LeetCode-POTD: 2000. Reverse Prefix of Word

POTD Link - https://leetcode.com/problems/reverse-prefix-of-word/description/

Approach
    1. find the index of first occurrence of the character
    2. reverse the string from start to the index
*/
class Solution {
public:
    string reversePrefix(string word, char ch) {

        int index = -1;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                index = i;
                break;
            }
        }
        reverse(word.begin(), word.begin()+index+1);

        return word;
    }
};
