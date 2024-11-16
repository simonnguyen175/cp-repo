#include<bits/stdc++.h>
#define ll long long
#define simon "Ndigits2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e4+5;
const int K=1e2+5;
const int MOD=1e9+7;

int n, k;
string a;
ll dp[N][K];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> k >> a;
    a=' '+a;
    memset(dp, 0, sizeof dp);
    for (int i=1; i<(a[1]-'0'); i++)
        dp[1][i%k]++;
    int s=a[1]-'0';
    for (int i=2; i<=n; i++){
        for (int j=0; j<k; j++)
            for (int t=0; t<=9; t++){
                dp[i][(j+t)%k]+=dp[i-1][j];
                dp[i][(j+t)%k]%=MOD;
            }
        for (int j=0; j<(a[i]-'0'); j++){
            dp[i][(s+j)%k]++;
            dp[i][(s+j)%k]%=MOD;
        }
        s=(s+(a[i]-'0'))%k;
    }
    int tmp=0;
    for (int i=1; i<a.size(); i++){
        tmp+=a[i]-'0';
        tmp%=k;
    }
    if ( tmp == 0 ) cout << dp[n][0]+1;
    else cout << dp[n][0];
    return 0;
}
