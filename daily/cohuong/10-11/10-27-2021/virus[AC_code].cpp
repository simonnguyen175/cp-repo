#include <bits/stdc++.h>
#define FOR(i, a, b)     for (int i = a; i <= b; ++i)
#define FOD(i, a, b)     for (int i = a; i >= b; --i)
#define next                 demacia                                                                                                               
using namespace std;
int TTest, num;
string virus, vac[203];
int next[10003][27], dp[503][503], res;

void sol() {
     int n = virus.size();
     virus = " " + virus;
     FOR(i, 0, 25) next[n + 2][i] = next[n + 1][i] = n + 1;
     FOD(i, n, 1) {
          FOR(j, 0, 25) next[i][j] = next[i + 1][j];
          next[i][virus[i] - 'A'] = i;
     }

     FOR(id, 1, num) {
          int m = vac[id].size(); int val = 0;
          vac[id] = " " + vac[id];
          FOR(i, 0, m) FOR(j, 1, m) dp[i][j] = n + 1;
          FOR(i, 1, m) FOR(j, 1, m)
               dp[i][j] = min(dp[i-1][j], next[dp[i-1][j-1] + 1][vac[id][i] - 'A']);
          FOR(j, 1, m)
               if (dp[m][j] < n + 1) val = j;
          res = max(res, val);
     }
     cout << res << '\n';
}

int main() {
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     freopen("virus.inp","r",stdin);
     freopen("virus.out","w",stdout);
     cin >> TTest;
     while (TTest--) {
          cin >> num >> virus;
          FOR(i, 1, num) cin >> vac[i];
          sol();
     }
}
