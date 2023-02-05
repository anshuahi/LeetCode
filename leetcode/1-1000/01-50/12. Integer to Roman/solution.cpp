class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        while(num > 0){
            if(num >= 1000){
                s += 'M';
                num -= 1000;
            }
            else if(num >= 900){
                s += "CM";
                num -= 900;
            }
            else if(num >= 500) {
                num -= 500;
                s += 'D';
            }
            else if(num >= 400){
                num -= 400;
                s += "CD";
            }
            else if(num >= 100){
                num -= 100;
                s += 'C';
            }

            else if(num >= 90){
                s += "XC";
                num -= 90;
            }
            else if(num >= 50) {
                num -= 50;
                s += 'L';
            }
            else if(num >= 40){
                num -= 40;
                s += "XL";
            }
            else if(num >= 10){
                num -= 10;
                s += 'X';
            }

            else if(num >= 9){
                s += "IX";
                num -= 9;
            }
            else if(num >= 5) {
                num -= 5;
                s += 'V';
            }
            else if(num >= 4){
                num -= 4;
                s += "IV";
            }
            else if(num >= 1){
                num -= 1;
                s += 'I';
            }
        }
        return s;
    }
};