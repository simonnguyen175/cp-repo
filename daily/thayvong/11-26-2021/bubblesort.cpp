#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t, n, ans = 0;
int a[N], bit[N];
map<int, int> id;

void update(int u){
  while ( u <= n ){
    bit[u] ++; u += u&(-u);
  }
}

int get(int u){
  int res = 0;
  while ( u > 0 ){
    res += bit[u]; u -= u&(-u);
  }
  return res;
}

void solve(){
  cin >> n;
  vector<int> cont;
  for (int i = 1; i <= n; i ++) cin >> a[i], cont.push_back(a[i]);
  sort(cont.begin(), cont.end());
  cont.erase(unique(cont.begin(), cont.end()), cont.end());
  for (int i = 1; i <= n; i ++) bit[i] = 0;
  for (int i = 0; i < cont.size(); i ++) id[cont[i]] = i + 1;
  ans = 0;
  for (int i = 1; i <= n; i ++){
//cout << get(id[a[i]]) << '\n';
    ans = max(ans, i - 1 - get(id[a[i]]));
    update(id[a[i]]);
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  if ( fopen("bubblesort.inp", "r") ){
    freopen("bubblesort.inp", "r", stdin);
    freopen("bubblesort.out", "w", stdout);
  }

  cin >> t;
  while ( t -- ) solve();
  return 0;
}
