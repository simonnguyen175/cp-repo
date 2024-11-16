#include<bits/stdc++.h>
#define simon "fib2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 50;

int t, n;
ll k, f[N], g[N];

ll dq(int n, ll k){
    if ( k == f[n] ) return g[n];
    if ( k <= f[n-2] ) return dq(n-2, k);
    if ( k > f[n-2] )
        return g[n-2] + dq(n-1, k - f[n-2]);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    f[0] =1, f[1] = 1;
    g[0] = 1, g[1] = 0;

    for (int i=2; i<=45; i++){
        f[i] = f[i-2] + f[i-1];
        g[i] = g[i-2] + g[i-1];
    }

    cin >> t;

    for (int i=1; i<=t; i++){
        cin >> n >> k;
        cout << dq(n, k) <<'\n';
    }

    return 0;
}


