#include<bits/stdc++.h>
#define simon "subsquar"
#define ll long long
using namespace std;
const int N = 2e2 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

int n;
char a[N][N];
ll HashRow[N][N], HashCol[N][N], HashRowRev[N][N], HashColRev[N][N], Pow[N];
bool dp[N][N][N];

ll getHashRow(int p, int i, int j, bool x){
    if ( x )
        return ( HashRow[p][j] - HashRow[p][i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
    else
        return ( HashRowRev[p][j] - HashRowRev[p][i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
}

ll getHashCol(int p, int i, int j, bool x){
    if ( x )
        return ( HashCol[p][j] - HashCol[p][i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
    else
        return ( HashColRev[p][j] - HashColRev[p][i-1] * Pow[j-i+1] + MOD * MOD ) % MOD;
}

void makeHash(int p, bool x){
    if ( x ){
        for (int i = 1; i <= n; i ++)
            HashRow[p][i] = ( HashRow[p][i-1] * base + a[p][i] - 'a' + 1 ) % MOD;
        for (int i = n; i >= 1; i --)
            HashRowRev[p][n-i+1] = ( HashRowRev[p][n-i] * base + a[p][i] - 'a' + 1 ) % MOD;
    }
    else{
        for (int i = 1; i <= n; i ++)
            HashCol[p][i] = ( HashCol[p][i-1] * base + a[i][p] - 'a' + 1 ) % MOD;
        for (int i = n; i >= 1; i --)
            HashColRev[p][n-i+1] = ( HashColRev[p][n-i] * base + a[i][p] - 'a' + 1 ) % MOD;
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    // tinh Pow
    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;

    // hash ngang
    for (int i = 1; i <= n; i ++)
        makeHash(i, 1);

    // hash doc
    for (int i = 1; i <= n; i ++)
        makeHash(i, 0);
}

void solve(){
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[i][j][1] = dp[i][j][0] = true;

    int ans = 1;

    for (int i = n-1; i >= 1; i --)
        for (int j = n-1; j >= 1; j --)
            for (int k = 2; k <= min(n-i+1, n-j+1); k ++){
                if ( getHashRow(i, j, j + k - 1, 1) == getHashRow(i + k - 1, j, j + k - 1, 1)
                    && getHashCol(j, i, i + k - 1, 1) == getHashCol(j + k - 1, i, i + k - 1, 1)
                    && getHashRow(i, n - j - k + 2, n - j + 1, 0) == getHashRow(i, j, j + k - 1, 1)
                    && getHashCol(j, n - i - k + 2, n - i + 1,0) == getHashCol(j, i, i + k - 1, 1))

                    dp[i][j][k] = dp[i+1][j+1][k-2];
                if ( dp[i][j][k] ) ans = max(ans, k);
            }

    cout << ans;
}

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    init();
    solve();
    return 0;
}
