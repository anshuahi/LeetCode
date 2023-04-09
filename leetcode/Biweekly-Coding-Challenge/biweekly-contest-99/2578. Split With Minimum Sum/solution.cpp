// https://leetcode.com/contest/biweekly-contest-99/
// https://leetcode.com/contest/biweekly-contest-99/problems/split-with-minimum-sum/

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        // cout << s;
        int a = 0;
        int b = 0;
        sort(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++){
            int d = s[i]-'0';
            if(i%2 == 0){
                a = a*10+d;
            }
            else {
                b = b*10 + d;
            }
        }
        return a+b;
    }
};