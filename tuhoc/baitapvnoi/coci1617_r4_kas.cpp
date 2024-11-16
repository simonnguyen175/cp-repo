#include<bits/stdc++.h>
using namespace std;
const int N = 505;

int n;
int a[N];
int f[N][100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    int s = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s += a[i];

    memset(f, -1, sizeof f);

    f[0][0] = 0;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= s; j ++) if ( f[i][j] != -1 ){
        f[i+1][j+a[i+1]] = max(f[i+1][j+a[i+1]], f[i][j] + a[i+1]);

        int mx = f[i][j], mn = f[i][j] - j + a[i+1];
        if ( mx < mn ) swap(mx, mn);
        f[i+1][mx-mn] = max(f[i+1][mx-mn], mx);

        f[i+1][j] = max(f[i+1][j], f[i][j]);
    }

    cout << s - f[n][0];

    return 0;
}
