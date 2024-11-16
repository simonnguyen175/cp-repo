#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], pw2[N];
map<ll, int> f, d, cnt;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    return mul(tmp, tmp);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = mul(pw2[i-1], 2);
    int inv2 = Pow(2, MOD-2);

    f[0] = 1;
    d[0] = 0, cnt[0] = 1;
    ll cur = 0;
    int ans = 0;

    for (int i = 1; i <= n; i ++){
        cur ^= a[i];

        f[cur] = mul(f[cur], pw2[i-d[cur]]);

        ans = add(ans, mul(add(f[cur], -2*cnt[cur]), inv2));

        d[cur] = i, f[cur] ++, cnt[cur] ++;
    }

    cout << ans;

    return 0;
}
