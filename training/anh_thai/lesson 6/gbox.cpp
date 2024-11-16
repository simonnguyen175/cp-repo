#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e2 + 10;

int n, m, X, Y, Z, T;
bool blo[N][N];
int d[N][N][4], trace[N][N][4];
struct cell{
    int x, y, t;
};
queue<cell> q;

void anal(int u, int v, int t, int val, int c){
    d[u][v][t] = val;
    trace[u][v][t] = c;
    q.push({u, v, t});
}

bool ck(int x, int y, int t){
    if ( d[x][y][t] == -1 ){
        if ( t == 0 ) return !blo[x][y];
        if ( t == 1 ) return ( !blo[x][y] && !blo[x][y+1] && !blo[x][y+2] );
        if ( t == 2 ) return ( !blo[x][y] && !blo[x+1][y] && !blo[x+2][y] );
    }
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("gbox.inp", "r") ){
        freopen("gbox.inp", "r", stdin);
        freopen("gbox.out", "w", stdout);
    }

    cin >> n >> m >> X >> Y >> Z >> T;
    X ++, Y ++, Z ++, T ++;

    memset(blo, 1, sizeof blo);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        char x; cin >> x;
        blo[i][j] = ( x == '1' );
    }

    memset(d, -1, sizeof d);

    d[X][Y][0] = 0;

    q.push({X, Y, 0});

    while ( q.size() ){
        int x = q.front().x, y = q.front().y, t = q.front().t;
        int val = d[x][y][t] + 1;
        q.pop();

        if ( t == 0 ){
            if ( ck(x, y+1, 1) ) anal(x, y+1, 1, val, 0);
            if ( ck(x+1, y, 2) ) anal(x+1, y, 2, val, 1);
            if ( ck(x, y-3, 1) ) anal(x, y-3, 1, val, 2);
            if ( ck(x-3, y, 2) ) anal(x-3, y, 2, val, 3);
        }

        if ( t == 1 ){
            if ( ck(x, y+3, 0) ) anal(x, y+3, 0, val, 0);
            if ( ck(x+1, y, 1) ) anal(x+1, y, 1, val, 1);
            if ( ck(x, y-1, 0) ) anal(x, y-1, 0, val, 2);
            if ( ck(x-1, y, 1) ) anal(x-1, y, 1, val, 3);
        }

        if ( t == 2 ){
            if ( ck(x, y+1, 2) ) anal(x, y+1, 2, val, 0);
            if ( ck(x+3, y, 0) ) anal(x+3, y, 0, val, 1);
            if ( ck(x, y-1, 2) ) anal(x, y-1, 2, val, 2);
            if ( ck(x-1, y, 0) ) anal(x-1, y, 0, val, 3);
        }
    }

    if ( d[Z][T][0] == -1 ) { cout << -1; return 0; }

    cout << d[Z][T][0] << '\n';

    int t = 0;

    vector<int> ans;
    while ( d[Z][T][t] ){
        int tt = trace[Z][T][t];

        ans.pb(tt);

        if ( t == 0 ){
            if ( tt == 0 ) T -= 3, t = 1;
            if ( tt == 1 ) Z -= 3, t = 2;
            if ( tt == 2 ) T ++, t = 1;
            if ( tt == 3 ) Z ++, t = 2;
        }
        else if ( t == 1 ){
            if ( tt == 0 ) T --, t = 0;
            if ( tt == 1 ) Z --, t = 1;
            if ( tt == 2 ) T += 3, t = 0;
            if ( tt == 3 ) Z ++, t = 1;
        }
        else if ( t == 2 ){
            if ( tt == 0 ) T --, t = 2;
            if ( tt == 1 ) Z --, t = 0;
            if ( tt == 2 ) T ++, t = 2;
            if ( tt == 3 ) Z += 3, t = 0;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans) cout << x << ' ';

    return 0;
}
