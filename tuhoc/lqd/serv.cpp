#include <bits/stdc++.h>
#define simon "paint"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=2e2+1;
const int M=1e3+1;
const int oo=1e9;

int n, m;
int cost[N][N], serv[M], dp[2][N][N];

int main(){
    FASTio
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> cost[i][j];
    for (int i=1; i<=m; i++)
        cin >> serv[i];

    // khoi tao
    for (int i=0; i<=1; i++)
        for (int j=1; j<=n; j++)
            for (int k=1; k<=n; k++)
                dp[i][j][k]=oo;
    dp[0][2][3]=dp[0][3][2]=0;
    serv[0]=1;

    // dp
    for (int t=1; t<=m; t++){
        bool cur=t%2;
        bool pre=!cur;
        int c=serv[t-1];

        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                dp[cur][i][j]=oo;

        for (int a=1; a<=n; a++)
            if ( a == c ) continue;
            else
                for (int b=1; b<=n; b++){
                    if ( b== c || b == a ) continue;
                    dp[cur][a][b]=min( dp[cur][a][b], dp[pre][a][b]+cost[c][serv[t]] );
                    dp[cur][b][c]=min( dp[cur][b][c], dp[pre][a][b]+cost[a][serv[t]] );
                    dp[cur][c][a]=min( dp[cur][c][a], dp[pre][a][b]+cost[b][serv[t]] );
                }
    }

    // get ans
    int ans=oo;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            ans=min(ans, dp[m%2][i][j]);
    cout << ans;
    return 0;
}
