#include<bits/stdc++.h>
#define simon "wbracket"
#define ll long long
#define int long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define BIT(x, k) ((x>>k)&1)
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
const int N = 3e2;
const ll oo = 1e18;
const int base = 120;

ll range(ll l, ll r){
    return l + rng() % ( r - l + 1 );
}

void file(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

ll n, k;
string ans = "";
ll f[N][N];

void calc(int id, int s){
    cout << id << ' ' << s << '\n';

    if ( f[id][s+base] != -1 ) return;

    ll res = 0;

    // "("
    calc(id + 1, s + 1);
    res = min(res + f[id+1][s+1+base], oo);

    // ")"
    calc(id + 1, s - 1);
    res = min(res + f[id+1][s-1+base], oo);

    f[id][s+base] = res;
}

void trace(){
    int s = 0;

    for (int i = 1; i <= n; i ++)
        if ( f[i][s+1+base] >= k ) ans += '(', s ++;
        else ans += ')', k -= f[i][s+1+base], s --;

    cout << ans;
}

signed main(){
    file();

    cin >> n >> k;
    n *= 2;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i ++) f[n][i+base] = 0;
    f[n][0+base] = 1;

    calc(0, 0);

    trace();

    return 0;
}
