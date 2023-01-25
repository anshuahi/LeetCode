class Solution {
public:
    vector<int> parent;

    void Union(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x == y)
            return;
        parent[x] = min(x, y);
        parent[y] = min(x, y);
    }

    int find(int a){
        if(a == parent[a])
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26, 0);
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(int i = 0; i < s1.size(); i++){
            Union(int(s1[i]-'a'), int(s2[i]-'a'));
        }
        string s = "";
        for(auto x: baseStr){
            s += char('a' + find(int(x-'a')));
        }

        return s;
    }
};