#include<bits/stdc++.h>
#define simon "winterfashion"
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, k;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    int cnt = 0;
    for (int i = 1, t; i <= n; i ++){
        cin >> t;
        if ( t < 20 ) cnt ++;
        else a[i] = 1;
    }
    if ( cnt > k ) { cout << -1; return 0; }

    k -= cnt;
    int ans = 0;
    a[0] = 1;
    for (int i = 1; i <= n; i ++)
        if ( a[i] != a[i-1] ) ans ++;
    if ( ans == 0 ) { cout << 0; return 0; }

    cnt = 0;
    vector<pi> cont;
    for (int i = 1; i <= n; i ++)
        if ( a[i] == 1 ) cnt ++;
        else if ( cnt ){
            cont.pb({cnt, i});
            cnt = 0;
        }
    if ( cnt ) cont.pb({cnt, n+1});

//    for (int i = 0; i <= n; i ++) cout << a[i]; cout << '\n';
//    for (auto it : cont) cout << "(" << it.fi << "," << it.se << ") ";
//    cout << '\n';
//    cout << ans << ' ' << k << '\n';

    sort(cont.begin(), cont.end());

    for (auto it : cont) if ( it.se != n+1 && it.se-it.fi != 1 )
        if ( k >= it.fi ) k -= it.fi, ans -= 2;
        else break;

    for (auto it : cont) if ( it.se == n+1 )
        if ( k >= it.fi ) k -= it.fi, ans --;
        else break;

    cout << ans;

    return 0;
}
