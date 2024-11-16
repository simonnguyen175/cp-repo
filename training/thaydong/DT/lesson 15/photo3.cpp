#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9;

int n, m, k;
pi a[N];
int pre[N], dp[N][N];

void ckmn(int &a, int b){
    a = min(a, b);
}

int sqr(int a){
    return a * a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        int mn = min(a[i].x, a[i].y);
        int mx = max(a[i].x, a[i].y);
        a[i].x = mn, a[i].y = mx;
        pre[a[i].x] = max(pre[a[i].x], a[i].y);
    }

    for (int i = 1; i <= m; i ++)
        pre[i] = max(pre[i-1], pre[i]);

    sort(a + 1, a + 1 + n, [&](pi b, pi c){
        return b.y < c.y;
    });

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
        dp[i][j] = oo;

    dp[0][0] = 0;
    int ans = oo;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++){
        int mnx = a[i].x;
        for (int t = i - 1; t >= 0; t --) if ( pre[mnx-1] <= a[t].y ){
            ckmn(dp[i][j], dp[t][j-1] + sqr(a[i].y - mnx + 1) - (mnx <= a[t].y ? sqr(a[t].y - mnx + 1) : 0));
            mnx = min(mnx, a[t].x);
        }
        if ( i == n ) ans = min(ans, dp[i][j]);
    }

    cout << ans;

    return 0;
}
