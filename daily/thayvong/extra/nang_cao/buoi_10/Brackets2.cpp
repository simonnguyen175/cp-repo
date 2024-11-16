#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool check(string s){
    int n=s.size();
    bool f[n+1][n+1];
    memset(f, false, sizeof f);
    for (int i=0; i<n-1; i++){
        string x=s.substr(i,2);
        if ( x == "()" || x == "(?" || x == "?)"
             || x == "??")
            f[i][i+1] = true;
    }
    for (int i=n-1; i>=0; i--)
        for (int j=i+3; j<n; j+=2){
            if ( s[i] == ')') continue;
            if ( s[j] == '(') continue;
            f[i][j]=f[i+1][j-1];
            for (int t=i+1; t<=j-2; t++)
                if (f[i][t] && f[t+1][j]){
                    f[i][j] = true;
                    break;
                }
        }
    return f[0][n-1];
}

int main(){
    freopen("brackets2.inp","r",stdin);
    freopen("brackets2.out","w",stdout);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> s;
        cout << check(s) <<"\n";
    }
    return 0;
}
