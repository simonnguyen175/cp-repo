#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
pi a[2*N];
int cnt[3][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= 2*n; i ++){
        cin >> a[i].fi >> a[i].se;

        if ( a[i].fi < 1 ) ans += 1 - a[i].fi, a[i].fi = 1;
        if ( a[i].fi > n ) ans += a[i].fi - n, a[i].fi = n;

        if ( a[i].se < 1 ) ans += 1 - a[i].se, a[i].se = 1;
        if ( a[i].se > 2 ) ans += a[i].se - 2, a[i].se = 2;

        cnt[a[i].se][a[i].fi] ++;
    }

    int lo = 0, hi = 0;
    for (int i = 1; i <= n; i ++){
        lo += cnt[1][i];
        hi += cnt[2][i];

        while ( lo > i && hi < i ) ans ++, lo --, hi ++;

        while ( hi > i && lo < i ) ans ++, hi --, lo ++;

        ans += abs(lo + hi - 2 * i);
    }

    cout << ans;

    return 0;
}
