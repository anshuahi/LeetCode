#define pb push_back
class Solution {
public:

    string addN_Spaces(string s, int n){
        while(n> 0){
            s += " ";
            n--;
        }
        return s;
    }

    string convertStringToSpecificLength(vector<string> &v, int w){
        string s = "";
        int t = 0;
        for(auto x: v){
            // s += x + " ";
            t += x.length();
        }

        int r= w- t;

        int n = v.size();
        if(n == 1){
            s = v[0];
            return addN_Spaces(s, r);
        }
        int p = r/(n-1);
        int rr = r%(n-1);
        cout << r << " " << n << " "<< p << " " << rr << endl;

        for(int i=0; i < n-1; i++){
            v[i] = addN_Spaces(v[i], p);
            if (i < rr) {
                v[i] += " ";
            }
            s += v[i];
        }

        s += v[n-1];

        return s;
    }
    string convertLastLine(vector<string> &v) {
        string s="";
        for(int i=0; i < v.size()-1; i++){
            s += v[i] + " ";
        }

        s += v.back();
        return s;
    }
    string addSpaces(string s, int w){
        int i = s.size();
        while(i < w){
            s += " ";
            i++;
        }

        return s;

    }
    vector<string> fullJustify(vector<string>& v, int w) {
        vector<string> b;
        vector<string> a;
        int st = 0, en = 0;
        int len = 0;
        while(en < v.size()){
            b.pb(v[en]);
            len += v[en].size();
            if(len + b.size() - 1 > w){
                b.pop_back();
                a.pb(convertStringToSpecificLength(b, w));
                b.clear();
                b.pb(v[en]);
                len = v[en].size();
            }
            en++;
        }
        
        a.pb(addSpaces(convertLastLine(b), w));
        return a;
    }
};