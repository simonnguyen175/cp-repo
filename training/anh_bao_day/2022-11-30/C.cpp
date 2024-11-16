#include<bits/stdc++.h>
using namespace std;
const int N = 4e2 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
const char ch[] = {'R', 'L', 'D', 'U'};
const int oo = 1e9 + 5;

int n, m, k;
int a[N][N], c[N][N], d[N][N];
char h[N][N];
struct node{
    int x, y, dxy;
    bool operator > (const node &a) const{
        return dxy > a.dxy;
    }
};
priority_queue<node, vector<node>, greater<node>> heap;

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= m );
}

bool check(int cap){
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        d[i][j] = oo;

    d[1][1] = 0;
    heap.push({1, 1, 0});

    while ( heap.size() ){
        int x = heap.top().x, y = heap.top().y, dxy = heap.top().dxy;
        heap.pop();

        if ( dxy != d[x][y] ) continue;

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) ) continue;
            int w = c[h[x][y]][ch[i]];
            if ( a[nx][ny] >= cap && a[x][y] - w >= cap && d[nx][ny] > dxy + w ){
                d[nx][ny] = dxy + w;
                heap.push({nx, ny, d[nx][ny]});
            }
        }
    }

    return d[n][m] <= k;
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];
    a[n][m] = oo;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> h[i][j];

    int lo = 0, hi = 1e9, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    c['U']['U'] = 0, c['U']['R'] = 1, c['U']['D'] = 2; c['U']['L'] = 3;
    c['R']['R'] = 0, c['R']['D'] = 1, c['R']['L'] = 2, c['R']['U'] = 3;
    c['D']['D'] = 0, c['D']['L'] = 1, c['D']['U'] = 2, c['D']['R'] = 3;
    c['L']['L'] = 0, c['L']['U'] = 1, c['L']['R'] = 2, c['L']['D'] = 3;

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
