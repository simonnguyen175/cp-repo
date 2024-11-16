#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e3+1;

int m, n, dp[N][N];
bool a[N][N], vis[N][N];
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};
queue<pair<int,int>> q;

void BFS(){
    q.push({1, 1});
    vis[1][1]=1;
    while ( !q.empty() ){
        int x=q.front().fi, y=q.front().se;
        q.pop();
        for (int i=0; i<4; i++){
            int xx=x+row[i], yy=y+col[i];
            if ( xx < 1 || yy < 1 ||xx > m || yy > n || a[xx][yy] || vis[xx][yy] ) continue;
            dp[xx][yy]=dp[x][y]+1;
            vis[xx][yy]=1;
            q.push({xx, yy});
        }
    }
}

int main(){
    freopen("shortest.inp","r",stdin);
    freopen("shortest.out","w",stdout);
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    dp[1][1]=1;
    BFS();
    if ( dp[m][n] > 0 )
    cout << dp[m][n];
    else cout << -1;
    return 0;
}
