#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int n;
int a[N], pos[N], p[N], q[N];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], pos[a[i]] = i;

    for (int i = 1; i <= n; i ++)
        q[i] = i;

    for (int t = 1; t <= 1000; t ++){
        shuffle(q + 1, q + 1 + n, rng);

        bool ck = 1;
        for (int i = 1; i <= n; i ++)
            ck &= ( q[i] != i );

        if ( !ck ) continue;

        for (int i = 1; i <= n; i ++)
            p[q[i]] = pos[i];

        for (int i = 1; i <= n; i ++)
            ck &= ( p[i] != i );

        if ( !ck ) continue;

        cout << "Possible\n";
        for (int i = 1; i <= n; i ++) cout << p[i] << ' '; cout << '\n';
        for (int i = 1; i <= n; i ++) cout << q[i] << ' '; cout << '\n';
        return;
    }

    cout << "Impossible\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
