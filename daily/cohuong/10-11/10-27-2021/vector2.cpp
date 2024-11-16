#include <bits/stdc++.h>
#define FOR(i, a, b)     for (int i = a; i <= b; ++i)
using namespace std;
const int M = 1e3 + 3, N = 23;
int m, n, a[M][N], dp[M], check[M][M], res;

void sol() {
     FOR(i, 1, m) sort(a[i] + 1, a[i] + n + 1);
     FOR(i, 1, m) a[i][n+1] = i;
     FOR(i, 1, m)
          FOR(j, i + 1, m)
               FOR(t, 1, n)
                    if (a[i][t] > a[j][t]) swap(a[i], a[j]); else
                         if (a[i][t] < a[j][t]) break;
     FOR(i, 1, m)
          FOR(j, i + 1, m) {
               bool ok = true;
               FOR(t, 1, n) ok &= a[i][t] <= a[j][t];
               if (ok) check[i][j] = 1;
          }
     FOR(i, 1, m)  {
          dp[i] = 1;
          FOR(j, 1, i - 1)
               if (check[j][i]) dp[i] = max(dp[i], dp[j] + 1);
          res = max(res, dp[i]);
     }
     cout << res << '\n';
     FOR(i, 1, res) {
          FOR(j, 1, m)
               if (dp[j] == i) cout << a[j][n+1] << ' ';
          cout << '\n';
     }
}

int main() {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     freopen("vector2.inp","r",stdin);
     freopen("vector2.out","w",stdout);
     cin >> m >> n;
     FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
     sol();
}
