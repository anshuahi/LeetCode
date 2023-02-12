class Solution {
public:
    string addStrings(string a, string b) {
        int n = a.size();
        int m = b.size();
        while(n < m){
            a = "0" + a;
            n++;
        }
        while(m < n){
            b = "0" + b;
            m++;
        }
        int carry = 0;
        int c,d;
        string s;
        for(int i = 0; i < m; i++){
            c = a[m-i-1] - '0';
            d = b[m-i-1] - '0';
            n = (c+d+carry);
            carry = n/10;
            s += (n%10 + '0');
        }
        if(carry){
            s += '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};