#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int m, n, k;
vector<int> row[N], col[N];
int a[N][N], bit[N][N];

void update(int u, int v){
    for (int i = u; i <= n + 1; i += i&-i)
    for (int j = v; j <= m + 1; j += j&-j)
        bit[i][j] ++;
}

int get(int u, int v){
    int res = 0;
    for (int i = u; i >= 1; i -= i&-i)
    for (int j = v; j >= 1; j -= j&-j)
        res += bit[i][j];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("mab.inp", "r", stdin);
    freopen("mab.out", "w", stdout);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j], row[i].pb(a[i][j]), col[j].pb(a[i][j]);

    for (int i = 1; i <= m; i ++)
        sort(row[i].begin(), row[i].end());
    for (int i = 1; i <= n; i ++)
        sort(col[i].begin(), col[i].end());

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        int alpha = lower_bound(row[i].begin(), row[i].end(), a[i][j]) - row[i].begin();
        int beta = col[j].end() - upper_bound(col[j].begin(), col[j].end(), a[i][j]);
        update(alpha + 1, beta + 1);
    }

    while ( k -- ){
        int alpha, beta;
        cin >> alpha >> beta;
        cout << get(alpha + 1, beta + 1) << '\n';
    }

    return 0;
}
