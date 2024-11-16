#include <bits/stdc++.h>
#define simon "divboard"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e3+5;
const ll oo=1e15;
const int MOD=123456789;

struct opt{
    int s1;
    int s2;
    int s3;
    int s4;
};

int m, n, a[N][N], b[N][N], ans=INT_MAX;
opt res;

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            b[i][j]=b[i-1][j]+a[i][j];

    for (int i=1; i<=m-1; i++){
        int s=0, tmp=0, kc=INT_MAX;
        for (int j=1; j<=n; j++)
            s+=b[i][j];
        for (int j=1; j<=n-1; j++){
            tmp+=b[i][j];
            if ( kc > abs(tmp-(s-tmp)) ){
                res.s1=tmp;
                res.s2=s-tmp;
                kc=abs(tmp-(s-tmp));
            }
        }

        s=0, tmp=0, kc=INT_MAX;
        for (int j=1; j<=n; j++){
            s+=b[m][j]-b[i][j];
        }
        for (int j=1; j<=n-1; j++){
            tmp+=b[m][j]-b[i][j];
            if ( kc > abs(tmp-(s-tmp)) ){
                res.s3=tmp;
                res.s4=s-tmp;
                kc=abs(tmp-(s-tmp));
            }
        }
        //cout << i << ' ' <<  max({res.s1, res.s2, res.s3, res.s4}) << ' ' <<min({res.s1, res.s2, res.s3, res.s4}) <<'\n';
        ans=min( ans, max({res.s1, res.s2, res.s3, res.s4}) - min({res.s1, res.s2, res.s3, res.s4}) );
    }
    cout << ans;
    return 0;
}
