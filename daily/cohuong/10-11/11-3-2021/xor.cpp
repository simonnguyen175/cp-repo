#include<bits/stdc++.h>
#define simon "xor"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define print(x, n) for (int i = 0; i <= n; i ++) cout << x[i] << ' '; cout << '\n';
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18;

ll n, A, B;
int a[45], b[45], c[N][45];
ll f[45][2][2];

ll calc(int id, bool oka, bool okb){
    if ( id < 0 ) return 0;

    if ( f[id][oka][okb] != -1 ) return f[id][oka][okb];

    int mn, mx;
    if ( oka ) mn = 0; else mn = a[id];
    if ( okb ) mx = 1; else mx = b[id];

    ll best = oo;

    //cout << id << ' ' << oka << ' ' << okb << ' ' << mx << ' ' << mn << '\n';

    for (int bit = mn; bit <= mx; bit ++){
        ll tmp = 0;
        for (int i = 1; i <= n; i ++)
            tmp += ( 1LL * ( bit ^ c[i][id] ) ) << id;
        //cout << " -> + " << bit << ' ' << tmp << ' ' << id - 1 << ' ' << ( oka | ( bit > a[id] ) ) << ' ' << ( okb | ( bit < b[id] ) ) << '\n';
        best = min(best, tmp + calc(id - 1, oka | ( bit > a[id] ), okb | ( bit < b[id] )));
    }

    f[id][oka][okb] = best;

    return best;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> A >> B;

    for (int i = 1; i <= n; i ++){
        ll x; cin >> x;
        for (int j = 0; j <= 40; j ++){
            c[i][j] = x % 2;
            x /= 2;
            //cout << c[i][j] << ' ';
        }
        //cout << '\n';
    }

    for (int i = 0; i <= 40; i ++) { a[i] = A % 2; A /= 2; }
    for (int i = 0; i <= 40; i ++) { b[i] = B % 2; B /= 2; }

    //cout << "--------------" << '\n';

    //print(a, 40); print(b, 40);

    memset(f, -1, sizeof f);

    cout << calc(40, 0, 0) << '\n';

    return 0;
}
