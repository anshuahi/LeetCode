bool comp(int &a, int &b){
    string astr = to_string(a);
    string bstr = to_string(b);
    return (astr + bstr) > (bstr + astr);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n= nums.size(), i;

        sort(nums.begin(), nums.end(), comp);
        string res="";
        for(i=0; i<n;i++){
            res = res + to_string(nums[i]);
        }
        if (res[0] == '0')
            return "0";
       else
           return to_string(stoi(res));
    }
};