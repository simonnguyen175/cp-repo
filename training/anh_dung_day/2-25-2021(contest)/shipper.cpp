#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N=1001, M=1001;

int n, m;
char cell[N][M];
int a[N][M];
vector<pair<int, int>> X;
pair<int, int> home;
queue<pair<int, int>> q;
int row[]={1, -1, 0,  0, 1, -1,  1, -1};
int col[]={1, -1, 1, -1, 0,  0, -1,  1};

void input(){
    freopen("shipper.inp","r",stdin);
    freopen("shipper.out","w",stdout);
    cin >> m >> n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> cell[i][j];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

bool check(int d){
    bool vis[N][M];
    for (int i=0; i<X.size(); i++){
        q.push(home);
        bool vis[N][M];
        bool check=0;
        while ( !q.empty() ){
            int x=q.front().fi, y=q.front().se;
            q.pop();
            if ( x == X[i].fi && y == X[i].se ) {check=1; break;}
            for (int i=0; i<8; i++){
                int xx=x+row[i], yy=y+col[i];
                if ( xx < 1 || yy < 1 || xx > m || yy > n ) continue;
                if ( abs(a[xx][yy] - a[x][y]) > d ) continue;
                if ( vis[xx][yy] ) continue;
                vis[xx][yy]=1;
                q.push({xx, yy});
            }
        }
        if ( check ) continue;
        else {return false; break;}
    }
    return true;
}

void solve(){
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++){
            if ( cell[i][j] == 'S' )
                home.fi=i; home.se=j;
            if ( cell[i][j] == 'X' )
                X.push_back({i, j});
        }
    /*int d=0, c=1e5, res;
    while ( d <= c ){
        int mid=(d+c)/2;
        if ( check(mid) ){
            res=mid;
            c=mid-1;
        }
        else d=mid+1;
    }
    cout << res;*/
}


int  main(){
    input();
    solve();
    return 0;
}
