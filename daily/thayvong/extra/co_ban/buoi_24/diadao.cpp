#include <bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "diadao"
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;

int k, x, y, dp[1005][1005];
bool close[1005][1005], vis[1005][1005];
queue<ii> q[2];
int row[]={0, 0, 1, -1};
int col[]={1, -1, 0, 0};

void BFS(){
    q[0].push({x, y});
    vis[x][y]=1;
    int id=0;
    bool c=1;

    while ( c ){
        while ( !q[id].empty() ){
            x=q[id].front().fi, y=q[id].front().se;
            if ( x == 0 && y == 0 ){
                cout << dp[0][0];
                return;
            }
            q[id].pop();
            for (int i=0; i<4; i++){
                int xx=x+row[i], yy=y+col[i];
                if ( xx < 0 || yy < 0 || xx > 1001 || yy > 1001 || vis[xx][yy]) continue;

                // queue cac cua mo loang ra de luu vao queue cac cua dong
                if ( !id ){
                    if ( close[xx][yy] ){
                        q[(id+1)%2].push({xx, yy});
                        dp[xx][yy]=dp[x][y]+1;
                        vis[xx][yy]=1;
                    }
                    else{
                        q[id].push({xx, yy});
                        dp[xx][yy]=dp[x][y];
                        vis[xx][yy]=1;
                    }
                }
                // queue cac cua dong loang ra de luu vao queue cac cua mo
                else{
                    if ( !close[xx][yy] ){
                        q[(id+1)%2].push({xx, yy});
                        dp[xx][yy]=dp[x][y];
                        vis[xx][yy]=1;
                    }
                    else{
                        q[id].push({xx, yy});
                        dp[xx][yy]=dp[x][y]+1;
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        id=(id+1)%2;
    }
}

int main(){
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    FASTio
    cin >> k >> x >> y;
    memset(vis, 0, sizeof vis);
    memset(close, 0, sizeof close);
    memset(dp, 0, sizeof dp);
    for (int i=1; i<=k; i++){
        int xx, yy;
        cin >> xx >> yy;
        close[xx][yy]=1;
    }
    BFS();
    return 0;
}
