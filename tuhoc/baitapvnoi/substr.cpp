#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 5;
const int base = 271;

string a, b;
ll Pow[N], Hash[N];

ll getHash(int i, int j){
    return ( Hash[j] - Hash[i-1] * Pow[j - i + 1] + MOD * MOD ) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a; b= ' ' + b;

    if ( n < m ) return 0;

    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + a[i] - 'a' + 1 ) % MOD;

    ll Hashb = 0;
    for (int i = 1; i <= m; i ++)
        Hashb = ( Hashb * base + b[i] - 'a' + 1 ) % MOD;

    for (int i = 1; i <= n - m + 1; i ++)
        if ( Hashb == getHash(i, i + m - 1) )
            cout << i << ' ';

    return 0;
}
