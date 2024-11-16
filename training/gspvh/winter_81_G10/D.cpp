#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const int oo = 1e9 + 5;

int sub, n, k;
struct drink{
    int p, t, id;
} a[N];
vector<int> cont[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("discounts.inp", "r", stdin);
    freopen("discounts.out", "w", stdout);

    cin >> sub >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].p >> a[i].t;
        a[i].id = i;
        cnt += ( a[i].t == 1 );
    }

    sort(a + 1, a + 1 + n, [&](drink x, drink y){
        if ( x.t == y.t ) return x.p > y.p;
        else return x.t < y.t;
    });

    double ans = 0;
    for (int i = 1; i <= k-1; i ++){
        if ( a[i].t == 1 ) ans += a[i].p*1.0/2;
        else ans += a[i].p;
        cont[i].pb(a[i].id);
    }

    int mn = oo;
    for (int i = k; i <= n; i ++){
        ans += a[i].p;
        cont[k].pb(a[i].id);
        mn = min(mn, a[i].p);
    }
    if ( cnt >= k ) ans += -mn + mn*1.0/2;

    cout << fixed << setprecision(1) << ans << '\n';
    for (int i = 1; i <= k; i ++){
        cout << cont[i].size() << ' ';
        for (int x : cont[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
