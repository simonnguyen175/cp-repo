#include <bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
int const N = 365;

int n, m, MOD;
char a[N][N];
int f[N][N][N][2];
int d1[4] = {1, 0, 0, 1};
int d2[4] = {-1, 0, 0, -1};

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> MOD;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];

    if ( n == 1 && m == 1 ){
        cout << 1 % MOD;
        return 0;
    }

    if ( a[1][1] == a[n][m] )
        f[1][1][n][0] = 1 % MOD;
    else f[1][1][n][1] = 1 % MOD;

    int tt;
    if ( (n+m-1) % 2 ) tt = (n+m)/2;
    else tt = (n+m-1)/2;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) if( i + j - 1 < tt )
        for (int k = n; k >= i; k --)
        for (int ok = 0; ok <= 1; ok ++) if ( f[i][j][k][ok] ){
            int t = n - k + m + 2 - i - j;

            for (int g = 0; g <= 2; g += 2)
            for (int h = 0; h <= 2; h += 2){
                pi p1 = {i + d1[g], j + d1[g + 1]};
                pi p2 = {k + d2[h], t + d2[h + 1]};
                if ( p1.fi > p2.fi || p1.se > p2.se || ok + (a[p1.fi][p1.se] != a[p2.fi][p2.se]) > 1 ) continue;
                add(f[p1.fi][p1.se][p2.fi][ok|(a[p1.fi][p1.se] != a[p2.fi][p2.se])], f[i][j][k][ok]);
            }
        }

    int ans = 0;
    for (int i = 1; i <= tt; i ++){
        int j = tt + 1 - i;
        for (int k = i; k <= n; k ++)
        for(int ok = 0; ok < 2; ok ++)
            add(ans, f[i][j][k][ok]);
    }
    cout << ans;

    return 0;
}
