#include<bits/stdc++.h>
using namespace std;

int main(){
    if ( fopen("luckyD.inp", "r") ){
        freopen("luckyD.inp", "r", stdin);
        freopen("luckyD.out", "w", stdout);
    }

    int t, d, X; cin >> t;
    while ( t -- ){
        cin >> d >> X;
        if ( X >= d * 10 )
            { cout << "YES\n"; continue; }
        bool ck = 0;
        for (int i = 1; i <= X/d; i ++)
            if ( (X - d * i) % 10  == 0 )
            { cout << "YES\n"; ck = 1; break; }
        if ( !ck ) cout << "NO\n";
    }
    return 0;
}
