#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000005;
const int MOD = 1e9 + 7;

ll t, n, m, c;
ll gt[N];

ll mu(ll x, ll y){
    if ( y == 0 ) return 1;
    ll tmp = mu(x, y/2);
    if ( y % 2 == 0 ) return (tmp*tmp)%MOD;
    else return (((tmp*tmp)%MOD)*x)%MOD;
}

ll C(int a, int b){
    if ( b > a ) return 0;
    if ( b == 0 ) return 1;
    return ( gt[a] * mu((gt[a-b]*gt[b])%MOD, MOD-2) )%MOD;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    gt[0] = 1;
    for (int i = 1; i < N; i ++)
        gt[i] = (gt[i-1] * i) % MOD;
    cin >> t;
    while ( t -- ){
        cin >> n >> m >> c;

        if ( c == 0 ){
            if ( m == n ) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }

        if ( n == m ){
            if ( c == 0 ) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }

        cout << (C(m+1,c)*C(n-m-1,c-1))%MOD << '\n';
    }
    return 0;
}
