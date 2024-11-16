#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("coins.inp", "r", stdin);
    freopen("coins.out", "w", stdout);

    int t, x, y;
    cin >> t;
    while ( t -- ){
        cin >> x >> y;
        if ( x % 2 == 1 ){
            cout << "NO\n";
        }
        else{
            if ( x == 0 ){
                if ( y % 2 == 0 ) cout << "YES\n";
                else cout << "NO\n";
            }
            else cout << "YES\n";
        }
    }

    return 0;
}
