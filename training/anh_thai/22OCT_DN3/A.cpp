#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1000003;

int fact[N], inv[N];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

vector<int> get(int x){
    vector<int> res;
    while ( x ){
        res.pb(x%MOD);
        x /= MOD;
    }
    return res;
}

int c(int n, int k){
    if ( k > n ) return 0;
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

int C(ll N, ll K){
    vector<int> n = get(N);
    vector<int> k = get(K);
    int res = 1;
    for (int i = 0; i < k.size(); i ++)
        res = mul(res, c(n[i], k[i]));
    return res;
}

void solve(){
    ll a, b, n, k;
    cin >> a >> b >> n >> k;
    int ans = 1;
    ans = mul(ans, Pow(a, n-1));
    ans = mul(ans, Pow(b, k-1));

    ans = mul(ans, C(n+k-2, n-1));
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= N-5; i ++) fact[i] = mul(fact[i-1], i);
    inv[N-5] = Pow(fact[N-5], MOD-2);
    for (int i = N-6; i >= 0; i --) inv[i] = mul(inv[i+1], i+1);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
