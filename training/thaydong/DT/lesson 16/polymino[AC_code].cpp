#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------------
const int N = 305, mod = 1e9+7;
int n, f[N][N][N];

void add(int &x, int y) {
    if ((x += y) > mod)
        x -= mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n; n--;
    f[1][1][2] = 1;
    for (int h = 1; h <= n; h++) {
        for (int l = 1; l <= n; l++) for (int r = l+1; r <= n; r++) {
            int v = f[h][l][r]; if (v == 0) continue;
            //left
            for (int mid = l+1; mid <= r; mid++) {
                add(f[h+1][mid][r+1], v);
            }
            //right
            for (int mid = l+1; mid <= r; mid++) {
                add(f[h+1][l][mid], v);
            }
            add(f[h+1][l][r+1], v*(l == 1) + v*(r == h+1));
        }
    }
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l+1; r <= n+1; r++)
            add(ans, f[n][l][r]);
    }
    cout << ans;
}
