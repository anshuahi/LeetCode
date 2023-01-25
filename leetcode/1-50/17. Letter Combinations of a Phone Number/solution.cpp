class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length() == 0){
            return v;
        }
        string a[] = {"", "", "abc", "def", "ghi", 
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> v1;
        v1.push_back("");
        for(int i = 0; i < digits.length(); i++){
            int d = digits[i] - '0';
            string s = a[d];
            for(int j = 0; j < s.length(); j++){
                for(int k = 0; k < v1.size(); k++){
                    v.push_back(v1[k] + s[j]);
                }
            }
            v1 = v;
            v.clear();
        }
        return v1;
    }
};