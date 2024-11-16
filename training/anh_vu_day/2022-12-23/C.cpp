#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e2 + 1;
const int M = 1e5 + 1;

int n;
pi a[N];
bool f[M], trace[N][M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi, s += a[i].fi, a[i].se = i;

    sort(a + 1, a + 1 + n, greater<pi>());

    int ans = 0, mn;
    f[0] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = s; j >= 0; j --){
        if ( j >= a[i].fi && f[j-a[i].fi] )
            f[j] = 1, trace[i][j] = 1;

        if ( f[j] && j > s/2 && j - a[i].fi <= s/2 && ans < j ){
            ans = j;
            mn = i;
        }
    }

    vector<int> res;
    res.pb(a[mn].se);
    ans -= a[mn].fi;
    for (int i = mn-1; i >= 1; i --)
        if ( trace[i][ans] == 1 ){
            res.pb(a[i].se);
            ans -= a[i].fi;
        }

    cout << res.size() << '\n';
    for (int x : res) cout << x << ' ';

    return 0;
}
