#include<bits/stdc++.h>
#define x first
#define y second
#define bug(x) cerr << _LINE_ << ": " << #x << " = " << (x) << '\n'

using namespace std;

const int maxn = 50005, K = 400, INF = 1e9;

typedef pair<int, int> ii;

int N, Q;

int child[maxn];
int C[maxn], H[maxn], par[maxn];

int tin[maxn], tout[maxn], timer;
int P[maxn << 1][19], Log[maxn << 1];
vector<int> G[maxn];

int id[maxn];
vector<int> nodes;

int cnt[maxn];
int num[maxn][K];
int moon[maxn][K];
vector<int> col;

void go(int u, int p = 0) {
  for (int i = 0; i < col.size(); ++i) {
    num[u][i] = C[u] == col[i];
    moon[u][i] = moon[p][i] + (C[u] == col[i]);
  }
  for (int v : G[u]) if (v != p) {
    go(v, u);
    for (int i = 0; i < col.size(); ++i)
      num[u][i] += num[v][i];
  }
}

int minn(int a, int b) {
  if (H[a] < H[b]) return a;
  return b;
}

void dfs(int u, int p = 0) {
  tin[u] = ++timer;
  id[u] = nodes.size();
  nodes.push_back(tin[u]);
  par[u] = p;
  P[tin[u]][0] = u;
  child[u] = 1;
  for (int v : G[u]) if (v != p) {
    H[v] = H[u] + 1;
    dfs(v, u);
    P[++timer][0] = u;
    child[u] += child[v];
  }
  tout[u] = timer;
}

int lca(int u, int v) {
  if (tin[u] > tin[v]) swap(u, v);
  int lg = Log[tin[v] - tin[u] + 1];
  return minn(P[tin[u]][lg], P[tin[v] - (1 << lg) + 1][lg]);
}

int d(int u, int v) {
  return H[u] + H[v] - 2 * H[lca(u, v)] + 1;
}

int countcol[maxn];
ii best = {-1, -1};

void upd(int u, int g, int del) {
  while (u != g) {
    countcol[C[u]] += del;
    best = max(best, {countcol[C[u]], C[u]});
    u = par[u];
    assert(u);
    if (!u) break;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
//  freopen("tqueryr3.inp", "r", stdin);
//  freopen("tqueryr3.out", "w", stdout);
  cin >> N >> Q;
  for (int i = 1; i <= N; ++i) {
    cin >> C[i];
    cnt[C[i]]++;
  }
  for (int i = 1; i <= N; ++i) {
    if (cnt[i] > K)
      col.push_back(i);
  }
  for (int u, v, i = 1; i < N; ++i) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  Log[0] = Log[1] = 0;
  for (int i = 2; i <= timer; ++i)
    Log[i] = Log[i / 2] + 1;
  for (int j = 1; j < 19; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= timer; ++i) {
      P[i][j] = minn(P[i][j - 1], P[i + (1 << j - 1)][j - 1]);
    }
  }
  go(1);
  assert((int)nodes.size() == N);
  for (int t, u, v, tests = 1; tests <= Q; ++tests) {
    cin >> t >> u;

    // T = 1
    if (t == 1) {
      if (child[u] > 2 * K) {
        bool ok = 0;
        for (int j = 0; j < col.size(); ++j)
          if (num[u][j] > child[u] / 2) {
            ok = 1;
            cout << col[j] << '\n';
            break;
          }
        if (!ok) cout << -1 << '\n';
        continue;
      }
      best = {-1, -1};
      for (int i = id[u]; nodes[i] <= tout[u] && i < nodes.size(); ++i) {
        assert(i < nodes.size());
        int v = P[nodes[i]][0];
        countcol[C[v]]++;
        best = max(best, {countcol[C[v]], C[v]});
      }
      if (best.x > child[u] / 2)
        cout << best.y << '\n';
      else
        cout << -1 << '\n';
      for (int i = id[u]; nodes[i] <= tout[u] && i < nodes.size(); ++i) {
        int v = P[nodes[i]][0];
        countcol[C[v]]--;
      }
    }


	// T = 2
	 else if (t == 2) {
      if (N - child[u] > 2 * K) {
        bool ok = 0;
        for (int j = 0; j < col.size(); ++j)
          if (cnt[col[j]] - num[u][j] > (N - child[u]) / 2) {
            ok = 1;
            cout << col[j] << '\n';
            break;
          }
        if (!ok) cout << -1 << '\n';
        continue;
      }
      best = {-1, -1};
      for (int i = 0; i < id[u]; ++i) {
        assert(i < nodes.size());
        int v = P[nodes[i]][0];
        countcol[C[v]]++;
        best = max(best, {countcol[C[v]], C[v]});
      }
      for (int i = N - 1; nodes[i] > tout[u]; --i) {
        assert(i < nodes.size());
        int v = P[nodes[i]][0];
        countcol[C[v]]++;
        best = max(best, {countcol[C[v]], C[v]});
      }
      if (best.x > (N - child[u]) / 2)
        cout << best.y << '\n';
      else
        cout << -1 << '\n';
      for (int i = 0; i < id[u]; ++i) {
        int v = P[nodes[i]][0];
        countcol[C[v]]--;
      }
      for (int i = N - 1; nodes[i] > tout[u]; --i) {
        int v = P[nodes[i]][0];
        countcol[C[v]]--;
      }
    }


	//T = 3
	else if (t == 3) {
      cin >> v;
      int dist = d(u, v);
      int g = lca(u, v);
      if (dist > 2 * K) {
        bool ok = 0;
        for (int j = 0; j < col.size(); ++j)
          if (moon[u][j] + moon[v][j] - 2 * moon[g][j] + (C[g] == col[j]) > dist / 2) {
            ok = 1;
            cout << col[j] << '\n';
            break;
          }
        if (!ok) cout << -1 << '\n';
        continue;
      }
      best = {-1, -1};
      upd(u, g, 1);
      upd(v, g, 1);
      countcol[C[g]]++;
      best = max(best, {countcol[C[g]], C[g]});
      if (best.x > dist / 2)
        cout << best.y << '\n';
      else
        cout << -1 << '\n';
      countcol[C[g]]--;
      upd(u, g, -1);
      upd(v, g, -1);
    }
  }
}

