#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define BIT(x, k) (((x)>>k)&1)
using namespace std;
const int N = 2e5 + 5;

ll n, l, r, k;
ll a[N], cnt[2][35], bita[N][35], bitl[35], bitr[35];
unordered_map<int, pi> f[35][2][2];

pi calc(int id, bool okl, bool okr, ll rem){
    if ( id < 0 )
        if ( rem == 0 ) return {0, 1};
        else return {0, 0};

    if ( f[id][okl][okr].find(rem) != f[id][okl][okr].end() )
        return f[id][okl][okr][rem];

    int mn, mx;

    if ( okl ) mn = 0; else mn = bitl[id];
    if ( okr ) mx = 1; else mx = bitr[id];

    pi best;
    for (int c = mn; c <= mx; c ++){
        ll nrem = ( rem + c * (1<<id) % k ) % k;
        pi tmp = calc(id - 1, okl | (c>bitl[id]), okr | (c<bitr[id]), nrem);

        if ( tmp.se == 0 ) continue;
        if ( best.fi < tmp.fi + cnt[1-c][id] * (1<<id) ){
            best.fi = tmp.fi + cnt[1-c][id] * (1<<id);
            best.se = tmp.se;
        }
        else if ( best.fi == tmp.fi + cnt[1-c][id] * (1<<id) ) best.se += tmp.se;
    }


    f[id][okl][okr][rem] = best;
    return best;
}

void trau(){
    ll d = ( l % k ? (l/k + 1) * k : l );
    pi ans;
    for (ll i = d; i <= r; i += k){
        ll tmp = 0;
        for (int j = 0; j <= 30; j ++)
            tmp += cnt[1-BIT(i, j)][j] * (1<<j);
        if ( tmp > ans.fi ){
            ans.fi = tmp; ans.se = 1;
        }else if ( tmp == ans.fi ) ans.se ++;
    }
    cout << ans.fi << '\n' << ans.se;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("xor.inp", "r") ){
        freopen("xor.inp", "r", stdin);
        freopen("xor.out", "w", stdout);
    }

    cin >> n >> l >> r >> k;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 30; j ++)
        bita[i][j] = a[i] % 2, a[i] /= 2;

    for (int i = 0; i <= 30; i ++)
        for (int j = 1; j <= n; j ++)
            if ( bita[j][i] ) cnt[1][i] ++;
            else cnt[0][i] ++;

    if ( r / k <= 1e5 ) { trau(); return 0; }

    for (int i = 0; i <= 30; i ++){
        bitl[i] = l % 2, l /= 2;
        bitr[i] = r % 2, r /= 2;
    }

    pi ans = calc(30, 0, 0, 0);

    cout << ans.fi << '\n' << ans.se;

    return 0;
}
