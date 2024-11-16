#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;

string s, p;
int n, m;
int nxt[N], f[N][N];

void ckmx(int &a, int b){
    if ( a == -1 ) a = b;
    else a = max(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("D.inp", "r") ){
        freopen("D.inp", "r", stdin);
        freopen("D.out", "w", stdout);
    }

    cin >> s >> p;
    n = s.size();
    m = p.size();
    s = ' ' + s;
    p = ' ' + p;

    for (int i = 1; i <= n; i ++){
        int cur = 0;
        for (int j = i; j <= n; j ++){
            if ( s[j] == p[cur+1] ) cur ++;
            if ( cur == m ) { nxt[i] = j; break; }
        }
    }

    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= i; j ++) if ( f[i][j] != -1 ){
        ckmx(f[i+1][j+1], f[i][j]);
        ckmx(f[i+1][j], f[i][j]);
        if ( nxt[i+1] )
            ckmx(f[nxt[i+1]][j+nxt[i+1]-i-m], f[i][j] + 1);
    }

    for (int i = 0; i <= n; i ++)
        cout << f[n][i] << ' ';

    return 0;
}
