#include<bits/stdc++.h>
#define simon "zero"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const ll N = 1e6 + 5;
const int oo = 1e9;

int q;
int f[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    for (int i = 1; i <= N - 5; i ++)
        f[i] = oo;

    f[0] = 0;
    for (ll i = 1; i <= N - 5; i ++){
        f[i] = min(f[i], f[i-1] + 1);
        for (ll j = i * 2; j <= min(i * i, N - 5); j += i)
            f[j] = min(f[j], f[i] + 1);
    }

    cin >> q;
    while ( q -- ){
        int x; cin >> x;
        cout << f[x] << '\n';
    }

    return 0;
}
