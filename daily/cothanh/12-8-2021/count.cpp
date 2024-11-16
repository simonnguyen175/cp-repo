#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define ll long long
using namespace std;
const int N = 1e2 + 5;
const int MOD = 1e9 + 7;

int n, k;
ll f[N][5000];

ll gt(){
    ll res = 1;
    for (int i = 1; i <= n; i ++) ( res *= i ) %= MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("count.in", "r") ){
        freopen("count.in", "r", stdin);
        freopen("count.out", "w", stdout);
    }

    cin >> n >> k;

    if ( n <= k ){ cout << gt(); return 0; }
    if ( k == 0 ){ cout << 1; return 0; }

    f[0][0] = 1;
    for (int i = 0; i < n; i ++)
    for (int mask = 0; mask < (1<<(2*k+1)); mask ++){
        bool ck = 1;
        for (int j = 0; j <= 2 * k; j ++)
            if ( ( i - (k - j) + 1 <= 0 && BIT(mask, j) ) || ( BIT(mask, j) && (i + j - k) > n ) )
                ck = 0;
        if ( !ck ) continue;

        int nmask = mask >> 1;
        for (int j = 0; j <= 2 * k; j ++){
            if ( !BIT(nmask, j) && i - (k - j) + 1 > 0 && i + j - k <= n )
                ( f[i+1][nmask|(1<<j)] += f[i][mask] ) %= MOD;
        }
    }

    cout << f[n][(1<<(k+1))-1];

    return 0;
}

