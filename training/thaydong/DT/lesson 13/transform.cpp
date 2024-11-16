#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 3e2 + 5;

int n, m;
string s;
int g[26][26], G[4][4][1<<7][1<<7];
int f[N][N];

int get(int msk, int l, int r){
    return ((msk>>l)&((1<<(r-l+1))-1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s;
    n = s.size();
    s = ' ' + s;
    cin >> m;
    for (int i = 1; i <= m; i ++){
        string t;
        getline(cin >> ws, t);
        g[t[2]-'a'][t[3]-'a'] |= 1<<(t[0]-'a');
    }

    int b[4], e[4];
    for (int i = 0; i <= 3; i ++){
        b[i] = i * 7;
        e[i] = i * 7 + ( i <= 2 ? 7 : 5 ) - 1;
    }

    for (int i = 0; i <= 3; i ++)
    for (int j = 0; j <= 3; j ++){
        int li = e[i] - b[i] + 1;
        int lj = e[j] - b[j] + 1;
        for (int ti = 0; ti < (1<<li); ti ++)
        for (int tj = 0; tj < (1<<lj); tj ++){
            int t = 0;
            for (int ii = 0; ii < li; ii ++) if ( BIT(ti, ii) )
            for (int jj = 0; jj < lj; jj ++) if ( BIT(tj, jj) )
                t |= g[i*7+ii][j*7+jj];
            G[i][j][ti][tj] = t;
        }
    }

    for (int i = 1; i <= n; i ++)
        f[i][i] = 1<<(s[i]-'a');
    for (int len = 2; len <= n; len ++)
    for (int i = 1; i <= n-len+1; i ++){
        int j = i + len - 1;
        for (int k = i; k < j; k ++){
            int t = 0;
            for (int l = 0; l <= 3; l ++)
            for (int r = 0; r <= 3; r ++){
                int tl = get(f[i][k], b[l], e[l]);
                int tr = get(f[k+1][j], b[r], e[r]);
                t |= G[l][r][tl][tr];
            }
            f[i][j] |= t;
        }
    }

    bool ck = 0;
    for (int i = 0; i <= 25; i ++) if ( BIT(f[1][n], i) ){
        cout << (char)('a'+i);
        ck = 1;
    }
    if ( !ck ) cout << "No Solution.";

    return 0;
}
