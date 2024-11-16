#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], dp[N][N];
unordered_map<int, int> d;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i <= n; i ++)
        dp[0][i] = 1;

    for (int i = 1; i <= n; i ++){
        d.clear();
        int cmex = 0;

        for (int j = i; j >= 1; j --){
            d[a[j]] = 1;
            while ( d[cmex] ) cmex ++;
            dp[i][cmex] = add(dp[i][cmex], dp[j-1][cmex]);
        }

        for (int j = 1; j <= n; j ++)
            dp[i][j] = add(dp[i][j], dp[i][j-1]);
    }

    cout << dp[n][n];

    return 0;
}
