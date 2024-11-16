#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e3 + 5;

int m, n;
int f[N][N];
vector<int> d[2];

void anal(int x, int id){
    for (int i = 1; i <= sqrt(x); i ++)
        if ( x % i == 0 ){
            d[id].pb(i);
            if ( i * i != x ) d[id].pb(x/i);
        }
}
pi ans;

int get(int x, int y, int u, int v){
    return f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("compression.inp", "r") ){
        freopen("compression.inp", "r", stdin);
        freopen("compression.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        if ( x == '1' )
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + 1;
        else
        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    }

    anal(m, 0); anal(n, 1);

    ans.fi = ans.se = 1;

    for (int x : d[0])
    for (int y : d[1]){
        bool ck = 1;

        for (int i = x; i <= m; i += x){
            if ( !ck ) break;
            for (int j = y; j <= n; j += y){
                int tmp = get(i-x+1, j-y+1, i, j);
                if ( tmp == 0 || tmp == ( x * y ) ) continue;
                else { ck = 0; break; }
            }
        }

        if ( ck ) if ( m*n/(x*y) < m*n/(ans.fi*ans.se) ) ans.fi = x, ans.se = y;
    }

    cout << m/ans.fi << ' ' << n/ans.se << '\n';

    for (int i = ans.fi; i <= m; i += ans.fi){
        for (int j = ans.se; j <= n; j += ans.se){
            int tmp = get(i-ans.fi+1, j-ans.se+1, i, j);
            if ( tmp == 0 ) cout << 0;
            else cout << 1;
        }
        cout << '\n';
    }

    return 0;
}
