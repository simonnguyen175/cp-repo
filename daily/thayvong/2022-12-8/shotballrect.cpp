#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 405;

int m, n, ans;
int a[N][N], b[N][N], row[N], col[N];

void solve(){
    for (int i = 1; i <= max(m, n); i ++) row[i] = 0, col[i] = 0;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        row[i] += a[i][j];
        col[j] += a[i][j];
    }

    /// 4 hang
    vector<int> crow;
    for (int i = 1; i <= m; i ++) crow.pb(row[i]);
    sort(crow.begin(), crow.end(), greater<int>());
    int tmp = 0;
    for (int i = 0; i <= min(3LL, m-1); i ++)
        tmp += crow[i];
    ans = max(ans, tmp);

    /// 3 hang 1 cot
    for (int i = 1; i <= n; i ++){
        tmp = col[i];
        crow.clear();
        for (int j = 1; j <= m; j ++)
            crow.pb(row[j]-a[j][i]);
        sort(crow.begin(), crow.end(), greater<int>());
        for (int j = 0; j <= min(2LL, m-1); j ++)
            tmp += crow[j];
        ans = max(ans, tmp);
    }

    /// 2 hang 2 cot
    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++){
        tmp = col[i] + col[j];
        crow.clear();
        for (int k = 1; k <= m; k ++)
            crow.pb(row[k]-a[k][i]-a[k][j]);
        sort(crow.begin(), crow.end(), greater<int>());
        for (int j = 0; j <= min(1LL, m-1); j ++)
            tmp += crow[j];
        ans = max(ans, tmp);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("shotballrect.inp", "r") ){
        freopen("shotballrect.inp", "r", stdin);
        freopen("shotballrect.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j], b[i][j] = a[i][j];

    solve();

    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        a[n-j+1][i] = b[i][j];
    swap(m, n);

//    for (int i = 1; i <= m; i ++){
//    for (int j = 1; j <= n; j ++)
//        cout << a[i][j] << ' ';
//    cout << '\n';
//    }

    solve();

    cout << ans;

    return 0;
}
