#include<bits/stdc++.h>
#define simon "cipher"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int t;
string s;

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void solve(){
    int n = s.size();
    s = ' ' + s;

    if ( n % 2 == 1 ) {cout << "AMBIGUOUS" << '\n'; return;}

    int a[55], res[55];

    for (int i = 1; i <= n; i ++)
        a[i] = s[i] - 'A';

    res[2] = a[1];

    for (int i = 4; i <= n; i += 2)
        res[i] = ( a[i-1] >= res[i-2] ? a[i-1] - res[i-2] : a[i-1] + 26 - res[i-2] );

    res[n-1] = a[n];
    for (int i = n-3; i >= 1; i -= 2)
        res[i] = ( a[i+1] >= res[i+2] ? a[i+1] - res[i+2] : a[i+1] + 26 - res[i+2] );

    for (int i = 1; i <= n; i ++)
        cout << (char) (res[i] + 'A');

    cout << '\n';
}

int main(){
    file();
    cin >> t;
    while ( t -- ){
        cin >> s;
        solve();
    }
}
