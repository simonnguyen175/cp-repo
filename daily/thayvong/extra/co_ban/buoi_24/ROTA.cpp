#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e3+1;

int m, n, a[N][N], rotten[N][N], ans;
queue<pair<int, int>> q;
bool vis[N][N];
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};

void BFS(){
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if ( a[i][j] == 2 ){
                q.push({i,j});
                rotten[i][j]=0;
                vis[i][j]=1;
            }
    while ( !q.empty() ){
        int x=q.front().fi, y=q.front().se;
        //cout << x <<' '<<y<<'\n';
        q.pop();
        for (int i=0; i<4; i++){
            int xx=x+row[i], yy=y+col[i];
            if ( xx < 1 || yy < 1 || xx > m || yy > n ) continue;
            if ( a[xx][yy] == 2 || a[xx][yy] == 0 || vis[xx][yy] ) continue;
            rotten[xx][yy]=rotten[x][y]+1;
            vis[xx][yy]=1;
            a[xx][yy]=2;
            q.push({xx, yy});
        }
    }
}

int main(){
    freopen("rota.inp","r",stdin);
    freopen("rota.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    memset(vis, 0, sizeof vis);
    BFS();
    ans=-1;
    for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++){
        ans=max(rotten[i][j], ans);
        if ( a[i][j] == 1 ){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}
