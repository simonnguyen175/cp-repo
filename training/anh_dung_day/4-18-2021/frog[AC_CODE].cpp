#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
typedef tuple<int, int, int> tpii;
int n, x, y, a[N][N], dp[N][N], res = 1;
vector<tpii> row;
multiset<tpii> r[N], c[N];

void pre(){
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            dp[i][j] = -1;
            row.push_back({make_tuple(a[i][j], i, j)});
        }
    sort(row.begin(), row.end());
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 4; ++j){
            r[i].insert(make_tuple(-1, 0, 0));
            c[i].insert(make_tuple(-1, 0, 0));
        }
    }
    dp[x][y] = 1;
    r[x].insert(make_tuple(1, x, y));
    c[y].insert(make_tuple(1, x, y));
    r[x].erase(r[x].begin()); c[y].erase(c[y].begin());
}
void reupdate(int u, int v){
    r[u].insert(make_tuple(dp[u][v], u, v));
    c[v].insert(make_tuple(dp[u][v], u, v));
    r[u].erase(r[u].begin());
    c[v].erase(c[v].begin());
}
void addh(int ra, int ca, int u){
    if(u < 1 || u > n) return;
    for(tpii i : r[u]){
        int q1 = get<1>(i), q2 = get<2>(i);
        if(q1 == 0 || q2 == 0) continue;
        if(abs(ca - q2) <= 1) continue;
        if(a[ra][ca] <= a[q1][q2]) continue;
        dp[ra][ca] = max(dp[ra][ca], dp[q1][q2] + 1);
    }
}
void addc(int ra, int ca, int u){
    if(u < 1 || u > n) return;
    for(tpii i : c[u]){
        int q1 = get<1>(i), q2 = get<2>(i);
        if(q1 == 0 || q2 == 0) continue;
        if(abs(ra - q1) <= 1) continue;
        if(a[ra][ca] <= a[q1][q2]) continue;
        dp[ra][ca] = max(dp[ra][ca], dp[q1][q2] + 1);
    }
}
void solve(){
    pre();
     for(tpii j : row){
        int v = get<0>(j);
        if(v <= a[x][y]) continue;
        int q1 = get<1>(j), q2 = get<2>(j);
        addh(q1, q2, q1 + 1);
        addh(q1, q2, q1 - 1);
        addc(q1, q2, q2 + 1);
        addc(q1, q2, q2 - 1);
        if(dp[q1][q2] == -1) continue;
        reupdate(q1, q2);
        res = max(res, dp[q1][q2]);
    }
    cout << res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
