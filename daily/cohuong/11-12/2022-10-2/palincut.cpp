#include<bits/stdc++.h>
#define ull unsigned long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9;
const int base = 31;

int n, t, k;
string s;
ull HashU[N], HashD[N], Pow[N];
int l[15], nxt[N][15], f[1<<15];

ull getU(int l, int r){
    return HashU[r] - HashU[l-1] * Pow[r-l+1];
}

ull getD(int r, int l){
    return HashD[l] - HashD[r+1] * Pow[r-l+1];
}

bool check(int l, int r){
    return ( getU(l, r) == getD(r, l) );
}

void xuli(){
    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> l[i], nxt[n+1][i] = nxt[n+2][i] = n+1;

    for (int j = 1; j <= k; j ++)
    for (int i = n; i >= 0; i --){
        nxt[i][j] = nxt[i+1][j];
        if ( i + l[j] - 1 > n ) continue;
        if ( check(i, i+l[j]-1) ){
            nxt[i][j] = i;
        }
    }

    for (int t = 0; t < (1<<k); t ++) f[t] = n+1;
    f[0] = 0;
    for (int t = 0; t < (1<<k); t ++){
        for (int i = 1; i <= k; i ++) if ( !BIT(t, i-1) )
            f[t|(1<<(i-1))] = min(f[t|(1<<(i-1))], nxt[f[t]+1][i] + l[i] - 1);
    }

    cout << ( f[(1<<k)-1] <= n ? "YES\n" : "NO\n" );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("palincut.inp", "r", stdin);
    freopen("palincut.out", "w", stdout);


    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i ++)
        HashU[i] = HashU[i-1] * base + s[i] - 'a' + 1;
    for (int i = n; i >= 1; i --)
        HashD[i] = HashD[i+1] * base + s[i] - 'a' + 1;

    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = Pow[i-1] * base;

    cin >> t;
    while ( t -- )
        xuli();

    return 0;
}
