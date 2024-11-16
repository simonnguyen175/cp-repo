#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int base = 2;
const int oo = 1e9;

string s;
int f[N][5][5];

int get(int t, int k){
    t = t - 'a' + k;
    if ( t < 0 ) return 25 + t + 1;
    if ( t > 25 ) return t - 26;
    return t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("removepalin.inp", "r") ){
        freopen("removepalin.inp", "r", stdin);
        freopen("removepalin.out", "w", stdout);
    }

    cin >> s;
    int n = s.size();
    s = ' ' + s;

    if ( n == 1 ) { cout << 0; return 0; }

    for (int i = 2; i <= n; i ++)
    for (int j = 0; j <= 4; j ++)
    for (int k = 0; k <= 4; k ++)
        f[i][j][k] = oo;

    for (int i = -2; i <= 2; i ++)
    for (int j = -2; j <= 2; j ++)
        if ( get(s[1], i) != get(s[2], j) )
            f[2][i+base][j+base] = abs(i) + abs(j);

    for (int i = 2; i < n; i ++)
    for (int j = -2; j <= 2; j ++)
    for (int k = -2; k <= 2; k ++){
        int t1 = get(s[i-1], j), t2 = get(s[i], k);
        if ( f[i][j+base][k+base] != oo && t1 != t2 ){
            for (int t = -2; t <= 2; t ++){
                int t3 = get(s[i+1], t);
                if ( t3 != t1  && t3 != t2 )
                    f[i+1][k+base][t+base] = min(f[i+1][k+base][t+base], f[i][j+base][k+base] + abs(t));
            }
        }
    }

    int ans = oo;

    for (int i = 0; i <= 4; i ++)
    for (int j = 0; j <= 4; j ++)
        ans = min(ans, f[n][i][j]);

    cout << ans;

    return 0;
}
