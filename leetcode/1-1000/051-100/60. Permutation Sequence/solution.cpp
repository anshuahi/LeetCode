#include <bits/stdc++.h>
class Solution {
public:

    string sortString(string s){
        sort(s.begin(), s.end());
        return s;
    }
    
    string nextPermutation(string s){
        int n = s.size()-2;
        while(n >= 0){
            if(s[n] < s[n+1]){
                break;
            }
            n--;
        }
  
        if(n < 0)
            return s;

        int ind = n+1, i;
        char c = '9';
        for(i = n+1; i < s.size(); i++){
            if(s[i] > s[n] && s[i] < c){
                c = s[i];
                ind = i;
            }
        }
        
        swap(s[n], s[ind]);
        s = s.substr(0, n+1) + sortString(s.substr(n+1));
        return s;
    }

    string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1; i <= n; i++){
            s += ('0' + i);
        }
        
        while (k > 1){
            s=nextPermutation(s);
            k--;
        }

        return s;
    }
};