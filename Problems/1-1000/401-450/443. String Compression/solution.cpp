class Solution {
public:
    int compress(vector<char>& v) {
        // v.push_back('#');
        string s;
        int count = 1;
        char c = v[0];
        for(int i = 1; i <v.size(); i++){
            if(c == v[i]){
                count++;
            }
            else {
                s += c;
                if(count > 1)
                    s += to_string(count);
                c = v[i];
                count = 1;
            }
        }
        s += c;
        if(count > 1)
            s += to_string(count);
        for(int i = 0; i < s.size(); i++){
            v[i] = s[i];
        }
        // cout << s << endl;
        return s.size();

    }
};