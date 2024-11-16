#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
ll gt[N], f[N], g[N];

ll Pow(ll a, ll b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return (((tmp*tmp)%MOD)*a)%MOD;
    return (tmp*tmp)%MOD;
}

ll C(ll n, ll k){
    return (gt[n]*Pow((gt[n-k]*gt[k])%MOD, MOD-2))%MOD;
}

int main(){
    cin >> n >> k;

    gt[0] = 1;
    for (int i = 1; i <= n; i ++)
        gt[i] = (gt[i-1]*i)%MOD;

    for (int i = k + 1; i <= n; i ++){
        f[i] = (f[i] + ((i-k-1)*gt[i-2])%MOD)%MOD;
        f[i] = (f[i] + (((g[i-1]-g[i-k-1]+MOD)%MOD)*gt[i-2])%MOD)%MOD;
        g[i] = g[i-1] + (f[i]*Pow(gt[i-1], MOD-2))%MOD;
    }

    ll ans = 0;
    for (int i = k + 1; i <= n; i ++)
        ans = (ans + (((f[i]*C(n-1, i-1))%MOD)*gt[n-i])%MOD)%MOD;

    cout << ans;

    return 0;
}
