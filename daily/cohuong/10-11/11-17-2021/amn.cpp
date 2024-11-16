#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e2 + 5;

int m, n, u, v;
int a[N][N], nx[N], ny[N];
pi contx[N], conty[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n >> u >> v;
    int mx = 0;
    pi pmx;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        if ( a[i][j] > mx ){
            mx = a[i][j];
            pmx = {i, j};
        }
    }


    for (int i = 1; i <= m; i ++)
        contx[i] = {a[i][pmx.se], i};
    for (int i = 1; i <= n; i ++)
        conty[i] = {a[pmx.fi][i], i};

    sort(contx + 1, contx + 1 + m, greater<pi>());
    sort(conty + 1, conty + 1 + n, greater<pi>());

    for (int i = 1; i <= m; i ++) nx[i] = contx[i].se;
    for (int i = 1; i <= n; i ++) ny[i] = conty[i].se;

    cout << a[nx[u]][ny[v]];

    return 0;
}
