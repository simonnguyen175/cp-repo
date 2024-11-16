#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, x, y;
pi a[N];
int f[N], g[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("vannghe.inp", "r", stdin);
    freopen("vannghe.out", "w", stdout);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
    }

    sort(a + 1, a + 1 + n, [](const pi &b, const pi &c){
        return b.fi - b.se > c.fi - c.se;
    });

    multiset<int> cont;
    int cur = 0;
    for (int i = 1; i <= n-y; i ++){
        if ( cont.size() < x ){
            cont.insert(a[i].fi);
            cur += a[i].fi;
        }
        else{
            cont.insert(a[i].fi);
            cur += a[i].fi;
            cur -= *cont.cbegin();
            cont.erase(cont.cbegin());
        }

        f[i] = cur;
    }

    cont.clear();
    cur = 0;
    for (int i = n; i > x; i --){
        if ( cont.size() < y ){
            cont.insert(a[i].se);
            cur += a[i].se;
        }
        else{
            cont.insert(a[i].se);
            cur += a[i].se;
            cur -= *cont.cbegin();
            cont.erase(cont.cbegin());
        }

        g[i] = cur;
    }

    int ans = 0;
    for (int i = x; i <= n-y; i ++)
        ans = max(ans, f[i] + g[i+1]);
    cout << ans;


    return 0;
}
/*
6
3 2
4 0
3 3
6 8
5 9
6 0
4 8
*/
