#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int oo = 1e9;

int n, m, p;
string a, b, c;
int f[N][N][N];
bool g[3][N][N][N];

bool ckmn(int &a, int b){
    if ( a > b ){
        a = b;
        return 1;
    }
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xcklt.inp", "r", stdin);
    freopen("xcklt.out", "w", stdout);

    cin >> a >> b >> c;
    n = a.size(), m = b.size(), p = c.size();
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;

    /// f(i, j, k)
    /// den ki tu i tren xau a
    /// khop pre j tren xau b
    /// khop pre k tren xau c
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= m; j ++)
    for (int k = 0; k <= p; k ++)
        f[i][j][k] = oo;
    f[0][0][0] = 0;
    int ans = oo;
    int ca = n, cb = m, cc;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= m; j ++)
    for (int k = 0; k <= p; k ++) if ( f[i][j][k] != oo ){
        if ( i == n && j == m && k < p ){
            if ( ans > f[i][j][k] ){
                ans = f[i][j][k];
                cc = k;
            }
            continue;
        }

        if ( a[i+1] == b[j+1] ){
            if ( b[j+1] == c[k+1] ){
                if ( ckmn(f[i+1][j+1][k+1], f[i][j][k] + 1) )
                    g[0][i+1][j+1][k+1] = g[1][i+1][j+1][k+1] = g[2][i+1][j+1][k+1] = 1;
            }
            else{
                if ( ckmn(f[i+1][j+1][k], f[i][j][k] + 1) )
                    g[0][i+1][j+1][k] = g[1][i+1][j+1][k] = 1, g[2][i+1][j+1][k] = 0;
            }
        }
        else{
            if ( a[i+1] == c[k+1] ){
                if ( ckmn(f[i+1][j][k+1], f[i][j][k] + 1) )
                    g[0][i+1][j][k+1] = g[2][i+1][j][k+1] = 1, g[1][i+1][j][k+1] = 0;
            }
            else{
                if ( ckmn(f[i+1][j][k], f[i][j][k] + 1) )
                    g[0][i+1][j][k] = 1, g[1][i+1][j][k] = g[2][i+1][j][k] = 0;
            }

            if ( b[j+1] == c[k+1] ){
                if ( ckmn(f[i][j+1][k+1], f[i][j][k] + 1) )
                    g[1][i][j+1][k+1] = g[2][i][j+1][k+1] = 1, g[0][i][j+1][k+1] = 0;
            }
            else{
                if ( ckmn(f[i][j+1][k], f[i][j][k] + 1) )
                    g[1][i][j+1][k] = 1, g[0][i][j+1][k] = g[2][i][j+1][k] = 0;
            }
        }
    }

    if ( ans == oo ) cout << "TRETRAU\n";
    else{
        cout << ans << '\n';
        string s = "";

        while ( ca || cb ){
            if ( g[0][ca][cb][cc] && g[1][ca][cb][cc] ){
                s += a[ca];
                cc -= g[2][ca][cb][cc];
                ca --, cb --;
            }
            else if ( g[0][ca][cb][cc] ){
                s += a[ca];
                cc -= g[2][ca][cb][cc];
                ca --;
            }
            else if ( g[1][ca][cb][cc] ){
                s += b[cb];
                cc -= g[2][ca][cb][cc];
                cb --;
            }
        }

        reverse(s.begin(), s.end());
        cout << s;
    }

    return 0;
}
