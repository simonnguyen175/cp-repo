#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

ll t, n, m;
ll fact[N], inv[N];
ll pown[N], pown1[N];

ll mu(int x, int y){
    if ( y == 0 ) return 1;
    ll tmp = mu(x, y/2);
    if ( y % 2 == 0 ) return (tmp*tmp)%MOD;
    else return (((tmp*tmp)%MOD)*x)%MOD;
}

ll C(int a, int b){
    if ( b == 0 ) return 1;
    if ( b > a ) return 0;
    if ( a == b ) return 1;
    return (((fact[a]*inv[a-b])%MOD)*inv[b])%MOD;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = (fact[i-1] * i) % MOD;


    inv[N-1] = mu(fact[N-1], MOD-2);
    for (int i = N-2; i >= 1; i --)
        inv[i] = ((i+1) * inv[i+1]) % MOD;

    cin >> t;
    while ( t -- ){
        cin >> m >> n;

        if ( m == n ){
            cout << 1 << '\n';
            continue;
        }

        pown[0] = pown1[0] = 1;
        for (int i = 1; i <= m-n; i ++){
            pown[i] = (pown[i-1]*n)%MOD;
            pown1[i] = (pown1[i-1]*(n-1))%MOD;
        }

        ll ans = 0;
        for (int i = 0; i <= m - n; i ++){
            ans = ( ans + (((C(m-i-1, n-1)*pown1[m-n-i])%MOD)*pown[i])%MOD )%MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}
