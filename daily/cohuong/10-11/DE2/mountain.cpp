#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 55;
const int MOD = 1e9 + 9;

int n, m;
string t;
pair<char, int> opt[] = { {'U', 1} , {'D', -1} };
int nxt[N][2], f[N][N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("mountain.in", "r") ){
//        freopen("mountain.in", "r", stdin);
//        freopen("mountain.out", "w", stdout);
//    }

    cin >> n;
    cin >> t;
    m = t.size();
    t = ' ' + t;

    for (int i = 0; i < m; i ++){
        for (int j = 0; j <= 1; j ++){
            string tmp = t.substr(1, i) + opt[j].fi;
            while ( tmp != t.substr(1, tmp.size()) )
                tmp.erase(0, 1);
            nxt[i][j] = tmp.size();
        }
    }

    nxt[m][0] = nxt[m][1] = m;

    f[0][0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
    for (int k = 0; k <= m; k ++) if ( f[i][j][k] )
        for (int t = 0; t <= 1; t ++) if ( j + opt[t].se >= 0 )
            ( f[i+1][j+opt[t].se][nxt[k][t]] += f[i][j][k] ) %= MOD;

    cout << f[n][0][m];

    return 0;
}
