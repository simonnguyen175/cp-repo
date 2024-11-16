#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n;
vector<int> adj[N];
ll f[N][2], d[N][2];

void dfs(int u){
  if ( u != 1 && adj[u].size() == 0 ){
    d[u][0] = 1; d[u][1] = 0;
    return;
  }

  d[u][0] = 1; d[u][1] = 0; ll tmp = 0, mx = -oo;
  for (int v : adj[u]){
    dfs(v);
    //cout << " -> " << f[v][1] << ' ' << f[v][0] << ' ' << d[u][1] << ' ' << d[u][0] << '\n';
    if ( f[v][1] == f[v][0] ) tmp += f[v][1], d[u][0] *= (d[v][0] + d[v][1]);
    if ( f[v][1] > f[v][0] ) tmp += f[v][1], d[u][0] *= d[v][1];
    if ( f[v][1] < f[v][0] ) tmp += f[v][0], d[u][0] *= d[v][0];

    mx = max(mx, f[v][0] - f[v][1]);
  }


  f[u][0] = tmp;
  f[u][1] = 1 + tmp + mx;

  //cout << u << ' ' << f[u][0] << ' ' << f[u][1] << ' ' << d[u][0] << ' ' << d[u][1] << '\n';

  for (int v : adj[u]) if ( f[v][0] - f[v][1] == mx ){
      tmp = d[u][0];
      if ( f[v][1] == f[v][0] ) tmp /= (d[v][0] + d[v][1]);
      if ( f[v][1] > f[v][0] ) tmp /= d[v][1];
      if ( f[v][1] < f[v][0] ) tmp /= d[v][0];
      d[u][1] += tmp * d[v][0];
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  freopen("treasury.inp", "r", stdin);
  freopen("treasury.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i ++){
    int u, nv, v;
    cin >> u >> nv;
    for (int j = 1; j <= nv; j ++)
      cin >> v, adj[u].pb(v);
  }

  memset(f, 0, sizeof f);
  memset(d, 0, sizeof d);

  dfs(1);

  cout << max(f[1][0], f[1][1]) << '\n';

  if ( f[1][1] == f[1][0] ) cout << d[1][0] + d[1][1];
  if ( f[1][1] > f[1][0] ) cout << d[1][1];
  if ( f[1][1] < f[1][0] ) cout << d[1][0];

  return 0;
}
