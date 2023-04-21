class Solution {
public:

    void print(vector<int> &t){
        for(auto x: t){
            cout << x << " ";
        }
        cout << endl;
    }

    bool isAllFreqK(vector<int> &freq, int k){
        for(int i : freq){
            if(i && i < k){
                return false;
            }
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        if(n < k)
            return 0;
        vector<int> freq(26, 0);
        vector<bool> less(26, false);
        for(auto x: s){
            freq[x-'a']++;
        }

        if(isAllFreqK(freq, k)){
            return n;
        }

        for(int i = 0; i < 26; i++){
            less[i] = (freq[i] < k);
        }
        
        int ans = 0, i = 0;
        int left = 0;
        while(i < n){
            if(less[s[i]-'a']){
                string p = s.substr(left, i-left);
                if(p != "")
                    ans = max(ans, longestSubstring(p, k));
                left = i+1;
            }
            i++;
        }
        string p = s.substr(left);
        ans = max(ans, longestSubstring(p, k));

        return ans;
    }
};