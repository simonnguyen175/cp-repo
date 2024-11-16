#include<bits/stdc++.h>
#define bug(x) cerr<<#x<<" = "<<x<<'\n'

using namespace std;
using ll = long long;

const int maxn = 50100;
const ll INF = 1e18;

int N, M, A[maxn];
int L[10], R[10], po[10], f[300];

ll dp[maxn][300];
bool valid[300];

int d(int msk, int i) {
  return (msk / po[i]) % 3;
}

void minn(ll &a, ll b) {
  if (a > b) a = b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
//  freopen("repgame.inp", "r", stdin);
//  freopen("repgame.out", "w", stdout);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> L[i] >> R[i];
  po[0] = 1;
  for (int i = 1; i <= M; ++i) po[i] = po[i - 1] * 3;
  for (int msk = 0; msk < po[M]; ++msk) {
    f[msk] = M;
    for (int i = 0; i < M; ++i) {
      if (d(msk, i) == 1) {
        f[msk] = i;
        break;
      }
    }
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int msk = 0; msk < po[M]; ++msk) {
        int x = d(msk, j);
        if (!x) {
          minn(dp[i][msk], dp[i - 1][msk]);
          if (L[j] <= i && i <= R[j]) {
            minn(dp[i][msk + po[j]], dp[i][msk]);
            minn(dp[i][msk + 2 * po[j]], dp[i][msk]);
          }
        } else if (x == 1) {
          if (i <= R[j])
            minn(dp[i][msk], dp[i - 1][msk]);
          minn(dp[i][msk + po[j]], min(dp[i - 1][msk], dp[i][msk]));
        } else
          minn(dp[i][msk], dp[i - 1][msk]);
      }
    }
    for (int msk = 0; msk < po[M]; ++msk) {
      dp[i][msk] += 1ll * A[i] * f[msk];
      for (int j = 0; j < M; ++j) {
        int x = d(msk, j);
        if (x == 1 && (i < L[j] || i > R[j]))
          dp[i][msk] = INF;
        if (x == 2 && (i < L[j]))
          dp[i][msk] = INF;
      }
    }
  }
  ll ans = INF;
  for (int msk = 0; msk < po[M]; ++msk)
    minn(ans, dp[N][msk]);
  cout<<ans<<'\n';
}
