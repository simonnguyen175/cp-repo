#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int32_t main() {
   cin.tie(0) -> sync_with_stdio(0);
   // int x; cin >> x;
   for (int i = 1; i <= 20; i++)
      cout << (char)(rnd(0, 25) + 'a');
   cout << '\n';
   for (int i = 1; i <= 10; i++)
      cout << (char)(rnd(0, 25) + 'a');
   cout << '\n';
   for (int i = 1; i <= 100; i++)
      cout << (char)(rnd(0, 25) + 'a');
   cout << '\n';
}
