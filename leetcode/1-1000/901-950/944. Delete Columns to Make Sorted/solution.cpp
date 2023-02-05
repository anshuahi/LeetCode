class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s[0].size();
        int count = 0;
        bool b;
        for(int i = 0; i < n; i++){
            b = true;
            for(int j = 1; j < s.size() && b; j++){
                if(s[j][i] < s[j-1][i]){
                    b = false;
                }
            }

            if(!b){
                count++;
            }
        }

        return count;
    }
};