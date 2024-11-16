#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int t, n, a[N];
bool res[N];
pair<int, int> range[N], f[N];
deque<int> dq;

void solve(){
    for(int i = 1; i <= n; i ++){
        range[i].fi = INT_MAX;
        res[i] = f[i].fi = 0;
    }

    for(int i = 1; i <= n; i ++){
        while( dq.size() && a[dq.back()] > a[i] ){
            range[i].fi = range[dq.back()].fi;
            range[dq.back()].se = i - 1;
            dq.pop_back();
        }
        range[i].fi = min(range[i].fi, i);
        dq.push_back(i);
    }

    range[n].se = n;
    while ( dq.size() ) {range[dq.back()].se = n; dq.pop_back();}

    int minK = n;
    for(int i = 1; i <= n; i ++){
        if ( !f[a[i]].fi ) f[a[i]] = range[i];
        else minK = min(minK, a[i]);
    }

    for(int i = 1; i <= minK; i ++){
        if ( !f[i].fi ) break;
        int x = f[i].se - f[i].fi + 1;
        if( x == n-i+1 ) res[x] = 1;

    }
    for(int i = 1; i <= n; i ++)
        cout << res[i];
    cout << '\n';
}

int main(){
    //freopen("permulation.inp", "r", stdin);
    //freopen("permulation.out", "w", stdout);
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        solve();
    }
    return 0;
}
