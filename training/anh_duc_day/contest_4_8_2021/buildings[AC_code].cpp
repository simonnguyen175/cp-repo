#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int t, n;
ll a[N], f[N], g[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    f[0] = g[0] = 0;
    deque<int> dq;
    for (int i = 1; i <= n; i ++){
        int cnt = 0;
        while ( dq.size() && a[dq.back()] >= a[i] ) dq.pop_back(), cnt ++;
        if ( dq.size() ) f[i] = f[dq.back()] + ( i - dq.back() ) * a[i];
        else f[i] = i * a[i];
        dq.push_back(i);
    }

    while ( dq.size() ) dq.pop_back();

    for (int i = n; i >= 1; i --){
        int cnt = 0;
        while ( dq.size() && a[dq.back()] >= a[i] ) dq.pop_back();
        if ( dq.size() ) g[i] = g[dq.back()] + ( dq.back() - i ) * a[i];
        else g[i] = ( n - i + 1 ) * a[i];
        dq.push_back(i);
    }

    ll res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, f[i] + g[i] - a[i]);

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    //freopen("buildings.inp", "r", stdin);
    //freopen("buildings.out", "w", stdout);

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
