#include<bits/stdc++.h>
#define simon "thuong"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll base = 31;
const ll MOD = 1e9 + 7;

int n, k;
string s, t;
ll Hashu[N], Hashd[N], Pow[N];

ll getHashU(int i, int j){
    return ( Hashu[j] - Hashu[i - 1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

ll getHashD(int i, int j){
    return ( Hashd[j] - Hashd[i + 1] * Pow[i - j + 1] + MOD * MOD ) % MOD;
}

bool check(int l, int r){
    int len = ( r - l + 1 ) / 2;
    return getHashU(l, l + len - 1) == getHashD(r, r - len + 1);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = ' ' + s;

    // make hash
    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    Hashd[n+1] = Hashu[0] = 0;

    for (int i = 1; i <= n; i ++)
        Hashu[i] = ( Hashu[i-1] * base + s[i] - 'a' + 1 ) % MOD;

    for (int i = n; i >= 1; i --)
        Hashd[i] = ( Hashd[i+1] * base + s[i] - 'a' + 1 ) % MOD;

    cin >> k;
    while ( k -- ){
        int l, r;
        cin >> l >> r;
        if ( check(l, r) ) cout << 1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
