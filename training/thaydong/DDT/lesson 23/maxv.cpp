#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
string s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("maxv.inp", "r") ){
        freopen("maxv.inp", "r", stdin);
        freopen("maxv.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    sort(s + 1, s + 1 + n, [&](string a, string b){
        string opt1 = a + b;
        string opt2 = b + a;
        for (int i = 0; i < opt1.size(); i ++)
            if ( opt1[i] != opt2[i] ) return opt1[i] > opt2[i];
        return true;
    });

    for (int i = 1; i <= n; i ++)
        cout << s[i];

    return 0;
}
