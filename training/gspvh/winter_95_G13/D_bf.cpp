#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;

tuple<bool, bool, bool> pre[MAXN][MAXN][MAXN];
char ans[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
int fiLen, seLen, thLen;
string a, b, c;

bool rolled;

int prevX, prevY, prevZ;
void update(int x, int y, int z, char &ch) {
   const int &cur = dp[x][y][z];
   prevX = x; prevY = y; prevZ = z;
   if (x < fiLen && a[x] == ch) x = min(x + 1, fiLen);
   if (y < seLen && b[y] == ch) y = min(y + 1, seLen);
   if (z < thLen && c[z] == ch) z = min(z + 1, thLen);
   if (dp[x][y][z] > cur + 1) {
      dp[x][y][z] = cur + 1;
      ans[x][y][z] = ch;
      pre[x][y][z] = make_tuple(prevX < x, prevY < y, prevZ < z);
   }
}

int curX, curY, curZ;

int32_t main() {
   cin.tie(0) -> sync_with_stdio(0);
//   if (fopen("XCKLT.inp", "r")) {
//      freopen("XCKLT.inp", "r", stdin);
//      freopen("XCKLT.out", "w", stdout);
//   }
   cin >> a >> b >> c;
   /// a in ans, b in ans, c not in ans
   fiLen = curX = a.size(); /// first
   seLen = curY = b.size(); /// second
   thLen = curZ = c.size(); /// third
   memset(dp, 60, sizeof dp);
   const int INF = dp[0][0][0];
   int kq = INF;
   dp[0][0][0] = 0;
   for (int i = 0; i <= fiLen; i++) {
      for (int j = 0; j <= seLen; j++) {
         for (int k = 0; k < thLen; k++) {
            const int &cur = dp[i][j][k];
            if (cur == INF) continue;
            if (i == fiLen && j == seLen && kq > cur) {
               curZ = k;
               kq = cur;
               continue;
            }
            update(i, j, k, a[i]);
            update(i, j, k, b[j]);
         }
      }
   }
   if (curZ == thLen) cout << "TRETRAU";
   else {
      string res = "";
      while (curX + curY + curZ) {
         res += (ans[curX][curY][curZ]);
         const auto &p = pre[curX][curY][curZ];
         if (get<0>(p)) --curX;
         if (get<1>(p)) --curY;
         if (get<2>(p)) --curZ;
      }
      reverse(res.begin(), res.end());
      cout << res.size();
   }
}
