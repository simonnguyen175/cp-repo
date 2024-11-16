#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 305;
const int oo = 1e9;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n, m, p;
vector<pi> cont[N*N];
pi fin;
int f[N][N], d[N][N];
queue<pii> q;
vector<pii> pre;

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= m );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    cin >> n >> m >> p;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        f[i][j] = oo;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        int x; cin >> x;
        cont[x].pb({i, j});
        if ( x == 1 ) f[i][j] = i + j - 2;
        if ( x == p ) fin = {i, j};
    }

    for (int i = 2; i <= p; i ++){
        if ( cont[i].size()*cont[i-1].size() <= m*n ){
            for (int j = 0; j < cont[i].size(); j ++){
                int x = cont[i][j].fi, y = cont[i][j].se;
                for (int k = 0; k < cont[i-1].size(); k ++){
                    int px = cont[i-1][k].fi, py = cont[i-1][k].se;
                    f[x][y] = min(f[x][y], f[px][py] + abs(x-px) + abs(y-py));
                }
            }
        }
        else{
            for (int j = 1; j <= n; j ++)
            for (int k = 1; k <= m; k ++)
                d[j][k] = -1;

            pre.clear();
            for (int j = 0; j < cont[i-1].size(); j ++){
                int x = cont[i-1][j].fi, y = cont[i-1][j].se;
                pre.pb({f[x][y], {x, y}});
            }
            sort(pre.begin(), pre.end());

            q.push({pre[0]});
            int it = 1;
            d[pre[0].se.fi][pre[0].se.se] = pre[0].fi;

//            cerr << i-1 << " -> " << i << " : \n";

            while ( q.size() ){
                int x = q.front().se.fi, y = q.front().se.se;
                int v = q.front().fi;
                q.pop();

//                cerr << x << ' ' << y << ' ' << v << '\n';

                while ( it < pre.size() && pre[it].fi <= v ){
                    q.push(pre[it]);
//                    cerr << "push " << pre[it].se.fi << ' ' << pre[it].se.se << '\n';
                    d[pre[it].se.fi][pre[it].se.se] = pre[it].fi;
                    it ++;
                }

                for (int j = 0; j <= 3; j ++){
                    int nx = x + row[j], ny = y + col[j];
                    if ( inside(nx, ny) && d[nx][ny] == -1 ){
                        d[nx][ny] = v + 1;
                        q.push({v+1, {nx, ny}});
//                        cerr << "push " << nx << ' ' << ny << '\n';
                    }
                }
            }

            for (int j = 0; j < cont[i].size(); j ++){
                int x = cont[i][j].fi, y = cont[i][j].se;
//                cerr << x << ' ' << y << ' ' << d[x][y] << '\n';
                f[x][y] = d[x][y];
            }
        }
    }

    cout << f[fin.fi][fin.se];

    return 0;
}
