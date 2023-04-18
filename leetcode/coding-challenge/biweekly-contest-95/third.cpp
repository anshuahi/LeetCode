#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    int p = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        p = p^v[i];
    }

    cout <<p << endl;

    int x = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                p = ((v[i]|v[j] )& v[k]);
                x = x^p;
                cout << p << " ";
            }
        }
    }

    cout << endl << x << endl;

}