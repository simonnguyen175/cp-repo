#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e6 + 5;

int n;
int w[N], f[N][2];
pi a[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> w[i];

    for (int i = 1; i < n; i ++)
        cin >> a[i].fi >> a[i].se;

    for (int i = 0; i < n; i ++) f[i][0] = 0, f[i][1] = w[i];

    for (int v = n-1, u; v >= 1; v --){
        if ( a[v].se == 0 ){
            u = a[v].fi;
            f[u][1] = f[v][0] + f[u][1];
            f[u][0] = max(f[v][0], f[v][1]) + f[u][0];
        }
        if ( a[v].se == 1 ){
            u = a[v].fi;
            f[u][1] = max(f[u][1] + max(f[v][1], f[v][0]), f[u][0]+f[v][1]);
            f[u][0] = f[u][0] + f[v][0];
        }
        if ( a[v].se == 2 ){
            u = a[v].fi;
            f[u][1] = max(f[u][1] + f[v][0], f[v][1] + f[u][0]);
            f[u][0] = f[v][0] + f[u][0];
        }
    }

    cout << max(f[0][0], f[0][1]);

    return 0;
}
