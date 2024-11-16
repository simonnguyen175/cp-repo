#include<bits/stdc++.h>
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 55;

int t, m, n;
int a[N][N], ans[N][N];
struct tt{
    int u, v, s, t;
};

void solve(){
    cin >> m >> n;

    int col[N];
    memset(col, 0, sizeof col);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        col[a[i][j]] ++;
    }

    multiset<pi> s;
    for (int i = 1; i <= n; i ++) s.insert({col[i], i});
    for (int i = 1; i <= n; i ++){
        auto mn = *s.cbegin();
        s.erase(s.find(mn));
        for (int j = 1; j <= mn.fi; j ++)
            ans[j][i] = mn.se;

        if ( !s.size() ) break;
        auto mx = *s.rbegin();
        s.erase(s.find(mx));
        for (int j = mn.fi+1; j <= m; j ++)
            ans[j][i] = mx.se, mx.fi --;
        s.insert(mx);
    }

//    cerr << "----------\n";
//    for (int i = 1; i <= m; i ++){
//        for (int j = 1; j <= n; j ++)
//            cout << ans[i][j] << ' ';
//        cout << '\n';
//    }

    vector<tt> res;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] != ans[i][j] ){
        bool ck = 0;
        for (int k = j + 1; k <= n; k ++)
            if ( a[i][k] == ans[i][j] ){
                res.pb({i, j, i, k});
                swap(a[i][j], a[i][k]);
                ck = 1; break;
            }
        if ( ck ) continue;
        for (int k = i+1; k <= m; k ++)
        for (int t = 1; t <= n; t ++)
            if ( a[k][t] == ans[i][j] ){
                res.pb({i, j, k, t});
                swap(a[i][j], a[k][t]);
            }
    }

    cout << res.size() << '\n';
    for (auto it : res)
        cout << it.u << ' ' << it.v << ' ' << it.s << ' ' << it.t << '\n';

//    cerr << "----------\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ) solve();

    return 0;
}
