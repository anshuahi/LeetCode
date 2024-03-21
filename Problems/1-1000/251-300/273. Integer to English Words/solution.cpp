class Solution {
public:
    vector<string> ones = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"
    };
    vector<string> two = {
        "Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string twoDigit(int n){
        if(n <= 20){
            return ones[n];
        }
        int ten = n/10;
        int unit = n%10;
        if(unit == 0){
            return two[ten];
        }
        return two[ten] + " " + ones[unit];
    }

    string tillThousand(int n){
        if(n == 0){
            return "";
        }
        int hundred = n/100;
        int tens = n%100;
        // cout << hundred << " " << tens << endl;
        if(hundred && tens){
            return ones[hundred] + " Hundred " + twoDigit(tens);
        }
        if(hundred){
            return ones[hundred] + " Hundred";
        }
        return twoDigit(tens);
    }
    string numberToWords(int n) {
        if(n == 0){
            return "Zero";
        }
        vector<int> v;
        while(n > 0){
            v.push_back(n%1000);
            n /= 1000;
        }

        string s = "";
        vector<string> big = {" ",  " Thousand ", " Million ", " Billion ",};
        int l = v.size()-1;
        while(l > 0){
            if(v[l] > 0){
                s += tillThousand(v[l]) + big[l];
            }
            l--;
        }
        s += tillThousand(v[0]);
        if(s[s.size()-1] == ' '){
            s.pop_back();
        }
        return s;
    }
};