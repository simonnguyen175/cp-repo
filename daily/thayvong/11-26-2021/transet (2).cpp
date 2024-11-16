#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, S;
ll adj[1005][35], sz[1005], f[1005][55];

void calc(int u, int s){
  if ( f[u][s] != -1 ) return;

  ll g[35][55];
  memset(g, -0x3f, sizeof g);
  g[0][0] = 0;
  s --;

//  cout << u << " -> ";
//  for (int i = 1; i <= sz[u]; i ++) cout << adj[u][i] << ' '; cout << '\n';

  for (int i = 1; i <= sz[u]; i ++)
  for (int j = 0; j <= s; j ++)
    for (int k = 0; k <= j; k ++){
      calc(adj[u][i], k);
      g[i][j] = max(g[i][j], g[i-1][j-k] + f[adj[u][i]][k]);
//      cout << u << ' ' << s << " : \n";
//      cout << " - " << i - 1  << ' ' << j - k << ' ' << g[i-1][j-k] << i << ' ' << j  << ' ' << g[i][j] << '\n';
//      cout << " + " << adj[u][i] << ' ' << k << ' ' << f[adj[u][i]][k] << '\n';
    }
  f[u][s+1] = g[sz[u]][s];
//  cout << "res " << sz[u] << ' ' << s << ' '  << g[sz[u]][s] << '\n';
//  cout << "res " << u << ' ' << s + 1 << ' ' << f[u][s+1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("transet.inp", "r") ){
      freopen("transet.inp", "r", stdin);
      freopen("transet.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
      cin >> sz[i];
      for (int j = 1; j <= sz[i]; j ++)
        cin >> adj[i][j];
    }
    cin >> S;

    //for (int i = 1; i <= n; i ++) cout << sz[i] << '\n';

    memset(f, -1, sizeof f);

    for (int i = 1; i <= n; i ++)
      f[i][0] = 1;

    for (int i = 1; i <= n; i ++)
      calc(i, S);

    ll ans = 0;

    for (int i = 1; i <= n; i ++) ans = max(ans, f[i][S]);

    cout << ans;

    return 0;
}
