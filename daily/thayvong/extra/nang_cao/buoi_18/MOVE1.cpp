#include <bits/stdc++.h>
#define simon "MOVE1"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=2e3+1;
const int oo=1e8;

int m, n, t, dp[N][N];
char a[N][N];
deque<ii> q;
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};

void BFS(){
    while ( !q.empty() ){
        int x=q.front().fi, y=q.front().se;
        //cout << x << ' ' << y << ' '<< dp[x][y] <<'\n';
        q.pop_front();
        for (int i=0; i<4; i++){
            int xx=x+row[i], yy=y+col[i];
            if ( xx < 1 || yy < 1 || xx > m || yy > n ) continue;
            if ( a[xx][yy]=='*' ) continue;
            if ( a[xx][yy] == a[x][y] ){
                if ( dp[xx][yy] > dp[x][y] ){
                    q.push_front({xx, yy});
                    dp[xx][yy]=dp[x][y];
                    //cout << xx << ' ' << yy << ' '<< dp[xx][yy] <<'\n';
                }
            }
            else{
                if ( dp[xx][yy] > dp[x][y]+1 ){
                    q.push_back({xx, yy});
                    dp[xx][yy]=dp[x][y]+1;
                }
            }
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> m >> n >> t;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            dp[i][j]=oo;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
            if ( a[i][j] == '*' ){
                q.push_back({i,j});
                dp[i][j]=0;
            }
        }
    BFS();
    for (int i=1; i<=t; i++){
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] <<'\n';
    }
    return 0;
}
