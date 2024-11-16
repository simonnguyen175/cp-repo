#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], bit[N];

void update(int u, int v){
  while ( u <= n ){
    bit[u] = max(bit[u], v);
    u += u&(-u);
  }
}

int get(int u){
  int res = 0;
  while ( u > 0 ){
    res = max(res, bit[u]);
    u -= u&(-u);
  }
  return res;
}

int main(){
  if ( fopen("insert.inp", "r") ){
    freopen("insert.inp", "r", stdin);
    freopen("insert.out", "w", stdout);
  }

  cin >> n;
  for (int i = 1; i <= n; i ++)
    cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= n; i ++){
    int tmp = get(a[i]-1);
    update(a[i], tmp + 1);
    ans = max(ans, tmp + 1);
  }
  ans = n - ans;
  cout << ans;
  return 0;
}
