#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 55;

int n;
int a[N], f[N][N][N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void ckmn(int &a, int b){
    a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("email.inp", "r", stdin);
    freopen("email.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cont.pb(a[i]);
    sort(cont.begin(), cont.end());
    for (int i = 1; i <= n; i ++) a[i] = id(a[i]);

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
    for (int x = 0; x <= cont.size(); x ++)
        f[i][j][x] = n+1;

    for (int i = 1; i <= n; i ++){
        f[i][i][a[i]] = 0;
        f[i][i][0] = 1;
    }

    for (int len = 2; len <= n; len ++)
    for (int i = 1; i <= n-len+1; i ++){
        int j = i + len - 1;

        for (int x = 1; x <= cont.size(); x ++)
        for (int k = i; k < j; k ++){
            ckmn(f[i][j][x], f[i][k][x] + f[k+1][j][x]);
            ckmn(f[i][j][x], f[i][k][0] + f[k+1][j][x]);
            ckmn(f[i][j][x], f[i][k][x] + f[k+1][j][0]);
        }

        for (int x = 1; x <= cont.size(); x ++)
            ckmn(f[i][j][0], f[i][j][x] + 1);
    }

    int ans = n+1;
    for (int i = 0; i <= cont.size(); i ++)
        ckmn(ans, f[1][n][i] + 1);
    cout << ans;

    return 0;
}
