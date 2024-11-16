#include<bits/stdc++.h>
using namespace std;

int t, n, a[205][205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
        if ( n == 1 ) cout << ( a[1][1] == 1 ? "YES\n" : "NO\n" );
        else cout << "NO\n";
    }
    return 0;
}
