#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int row[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int col[] = {-1, 1, 0, 0, 1, -1, 1, -1};

struct ver{
    int x, y, val;
};

bool cmp(ver a, ver b){
    return a.val > b.val;
}

bool operator > (const ver& a, const ver& b){
    return a.val > b.val;
}

int n, q, m;
char cell[N][N];
int a[N][N], pos[N][N];
int Par[N*N], Rank[N*N], ans[N*N];
ver b[N*N];
vector<int> qr[N][N];
set<int> cont[N*N];

void file(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    if ( fopen("hangar.inp", "r") ){
        freopen("hangar.inp", "r", stdin);
        freopen("hangar.out", "w", stdout);
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> cell[i][j];

    cin >> q;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            qr[i][j].clear();
    for (int i = 1; i <= q; i ++){
        int ax, ay, bx, by;
        cin >> ax >> ay;
        cin >> bx >> by;
        qr[ax][ay].push_back(i);
        qr[bx][by].push_back(i);
    }


    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            a[i][j] = INT_MAX;

    priority_queue<ver, vector<ver>, greater<ver>> heap;
    for (int i = 1; i <= n; i ++)
        for (int  j = 1; j <= n; j ++){
            if ( cell[i][j] == '#' ){
                a[i][j] = 0;
                heap.push({i, j, 0});
                continue;
            }

            if ( ( i == 1 || i == n || j == 1 || j == n ) && cell[i][j] == '.' ){
                a[i][j] = 1;
                heap.push({i, j, 1});
                continue;
            }
        }

    while ( heap.size() ){
        int x = heap.top().x, y = heap.top().y, val = heap.top().val;
        heap.pop();
        for (int i = 0; i < 8; i ++){
            int xx = x + row[i], yy = y + col[i];
            if ( xx < 1 || xx > n || yy < 1 || yy > n ) continue;
            if ( a[xx][yy] == INT_MAX ){
                if ( val == 0 ){
                    a[xx][yy] = 1;
                    heap.push({xx, yy, 1});
                }
                else{
                    a[xx][yy] = val + 2;
                    heap.push({xx, yy, a[xx][yy]});
                }
            }
        }
    }

    m = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( a[i][j] > 0 )
                b[++m] = {i, j, a[i][j]};

    sort(b + 1, b + 1 + m, cmp);

    memset(pos, 0, sizeof pos);
    for (int i = 1; i <= m; i ++)
        pos[b[i].x][b[i].y] = i;

    for (int i = 1; i <= m; i ++){
        Par[i] = i;
        Rank[i] = 0;
        if ( qr[b[i].x][b[i].y].size() > 0 )
            for (int it : qr[b[i].x][b[i].y] )
                cont[i].insert(it);
    }
}

void combine(int u, int v, int sz){
    std::set<int>::iterator it;
    if ( cont[u].size() == 0 ){
        for (it = cont[v].begin(); it != cont[v].end(); ++ it)
            cont[u].insert(*it);
        return;
    }

    for (it = cont[v].begin(); it != cont[v].end(); ++ it){
        auto p = cont[u].find(*it);
        if ( p != cont[u].end() ){
            ans[*p] = sz;
            cont[u].erase(p);
        }
        else cont[u].insert(*it);
    }
}

int Find(int u){
    if ( Par[u] != u ) return Par[u] = Find(Par[u]);
    else return u;
}

void Join(int u, int v, int sz){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        if ( cont[v].size() > 0 ) combine(u, v, sz);
    }
}

void solve(){
    for (int i = 1; i <= m; i ++){
        int x = b[i].x, y = b[i].y;
        for (int j = 0; j < 4; j ++){
            int xx = x + row[j], yy = y + col[j];
            if ( xx > n || xx < 1 || yy > n || yy < 1 ) continue;
            if ( pos[xx][yy] > 0 && b[pos[xx][yy]].val >= b[i].val && b[pos[xx][yy]].val != INT_MAX  )
                Join(i, pos[xx][yy], b[i].val);
        }
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';
}

int main(){
    file();
    init();
    solve();
    return 0;
}
