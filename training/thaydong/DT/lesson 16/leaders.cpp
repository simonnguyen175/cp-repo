#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int oo = INT_MAX;

int m, n;
int a[50], id[50], sum[20];
vector<int> cont[20];
int dp[1<<15][50][50];

void ckmn(int &a, int b){
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;
    int cnt = 0;
    for (int i = 0; i < m; i ++){
        int s;
        cin >> s;
        for (int j = 1, x; j <= s; j ++){
            cin >> x;
            a[cnt] = x;
            id[cnt] = i;
            sum[i] += x;
            cont[i].pb(cnt);
            cnt ++;
        }
    }

    /// dp(msk, i, j)
    /// msk bieu hien co nhung team nao co leader
    /// thang dau chuoi la i
    /// thang hien tai la j (chua bo vao team nao)

    memset(dp, -1, sizeof dp);
    for (int x : cont[0])
        dp[0][x][x] = 0;

    int ans = oo;
    for (int t = 0; t < (1<<m); t ++)
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++) if ( dp[t][i][j] != -1 ){
//        cout << t << ' ' << i << ' ' << j << ' ' << dp[t][i][j] << '\n';

        /// ket thuc chuoi
        if ( a[j] >= sum[id[i]] - a[i] ){
            int nt = t | (1<<id[i]);

            if ( nt == (1<<m)-1 ){
                ans = min(ans, dp[t][i][j] + a[j]);
            }
            else{
                int rt = ((1<<m)-1)&(~nt);
                int nxt = __builtin_ctz(rt);
//                cout << " -> " << nxt << '\n';
                for (int k : cont[nxt])
                ckmn(dp[nt][k][k], dp[t][i][j] + a[j]);
            }
        }

        /// tiep tuc chuoi
        for (int nxt = 0; nxt < m; nxt ++) if ( !BIT(t, nxt) )
        for (int k : cont[nxt]) if ( a[j] >= sum[nxt] - a[k] )
            ckmn(dp[t|(1<<nxt)][i][k], dp[t][i][j] + a[j]);
    }

//    cout << dp[1][3][3] << '\n';

    cout << (ans == oo ? -1 : ans);

    return 0;
}
