#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e15;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n;
int a[N][N];
int d[20][N][N], dp[(1<<15)+5], cost[(1<<15)+5];
vector<pi> nets;

int string2Int(string s){
    int res = 0;
    for (int i = 0; i < (int)s.size(); i ++){
        res = res*10 + s[i] - '0';
    }
    return res;
}

struct Node{
    int x;
    int y;
    int d;
};

bool operator > (const Node& a, const Node& b){
    return a.d > b.d;
}

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= n );
}

void minimize(int &a, int b){
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

void dijkstra(int id, int x, int y){
    priority_queue<Node, vector<Node>, greater<Node>> heap;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        d[id][i][j] = oo;

    d[id][x][y] = 0;
    heap.push({x, y, 0});
    while ( heap.size() ){
        int x = heap.top().x, y = heap.top().y, dxy = heap.top().d;
        heap.pop();

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( inside(nx, ny) && d[id][nx][ny] > dxy + a[nx][ny] ){
                d[id][nx][ny] = dxy + a[nx][ny];
                heap.push({nx, ny, d[id][nx][ny]});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tmp.inp", "r") ){
        freopen("tmp.inp", "r", stdin);
        freopen("tmp.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        string x;
        cin >> x;
        if ( x == "*" ){
            a[i][j] = 0;
            nets.pb({i, j});
        }
        else{
            a[i][j] = string2Int(x);
        }
    }

    int nn = nets.size();

    for (int i = 0; i < nn; i ++){
        dijkstra(i, nets[i].fi, nets[i].se);
    }

    for (int msk = 0; msk < (1<<nn); msk ++){
        dp[msk] = -1;

//        cout << msk << " : \n";
        vector<int> pos;
        for (int i = 0; i < nn; i ++) if ( BIT(msk, i) ){
            pos.push_back(i);
//            cout << nets[i].fi << ' ' << nets[i].se << " , ";
        }
//        cout << '\n';

        cost[msk] = oo;
        for (int x = 1; x <= n; x ++)
        for (int y = 1; y <= n; y ++) if ( a[x][y] != 0 ) {
            int tmp = 0;
            for (int i : pos)
                tmp += d[i][x][y];
            cost[msk] = min(cost[msk], tmp);
        }
        if ( __builtin_popcount(msk) == 1 ) cost[msk] = 0;
//        cout << "-> " << cost[msk] << '\n';
    }


    dp[0] = 0;
    for (int msk = 0; msk < (1<<nn); msk ++) if ( dp[msk] != -1 ){
        for (int i = 0; i < nn; i ++) if ( !BIT(msk, i) ){
            int nmsk = msk | (1<<i);
            minimize(dp[nmsk], dp[msk] + cost[nmsk]);
        }
    }

    cout << dp[(1<<nn)-1];

    return 0;
}
