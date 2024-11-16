#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, k, m, a[N], s[N];

int main() {
   ios :: sync_with_stdio (0);
   cin.tie (0);  cout.tie (0);

   freopen ("longqueue.inp", "r", stdin);
   freopen ("longqueue.out", "w", stdout);

   cin >> n >> k;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = (a[i] >= k);
      s[i] = s[i-1] + a[i];
   }

   cin >> m;
   int l = 1, r = n;
   for (int i = 1; i <= m; i++) {
      int type; cin >> type;
      if (type == 1) {
         int x; cin >> x; x = (x >= k);
         a[++r] = x; s[r] = s[r-1] + x;
      }
      else if (type == 2) {
         l++;
      }
      else if (type == 3) {
         int x; cin >> x; x += l;
         cout << s[x - 1] - s[l - 1] << '\n';
      }
   }

   return 0;
}
