#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9 + 5;

int n;
pi a[N];
int pre[N], suf[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("moo.inp", "r") ){
        freopen("moo.inp", "r", stdin);
        freopen("moo.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n);

    pre[0] = oo;
    for (int i = 1; i <= n; i ++)
        pre[i] = min(pre[i-1], a[i].se);

    suf[n+1] = -oo;
    for (int i = n; i >= 1; i --)
        suf[i] = max(suf[i+1], a[i].se);

    int ans = 1;
    for (int i = 1; i < n; i ++)
        if ( pre[i] > suf[i+1] )
            ans ++;

    cout << ans;
}
