#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int t, L, R;
int a[2][15], c[15];
int f[11][2][2][11][11];

int get(int id, int ok, int ok1, int len, int last){
    if ( id > 10 ) return !len;
    if ( f[id][ok][ok1][len][last] != -1 ) return f[id][ok][ok1][len][last];

    ll res = 0;
    for (int cs = 0; cs <= max(ok*9, c[id]); cs ++){
        int nok = ok|(cs<c[id]);
        res += get(id+1, nok, ok1|(cs>0), len, last);
        if ( ok1 && cs > last ) res += get(id+1, nok, 1, len-1, cs);
        if ( !ok1 && cs > 0 ) res += get(id+1, nok, 1, len-1, cs);
    }

    f[id][ok][ok1][len][last] = res;
    return res;
}

void solve(){
    cin >> L >> R;
    L --;
    for (int i = 10; i >= 1; i --)
        a[0][i] = L % 10, L /= 10;

    int scs = 0;
    for (int i = 10; i >= 1; i --){
        if ( R > 0 ) scs ++;
        a[1][i] = R % 10, R /= 10;
    }

    int res;
    for (int i = scs; i >= 1; i --){
        memset(f, -1, sizeof f);
        for (int j = 1; j <= 10; j ++) c[j] = a[1][j];
        res = get(1, 0, 0, i, -1);

        if ( !res ) continue;

        memset(f, -1, sizeof f);
        for (int j = 1; j <= 10; j ++) c[j] = a[0][j];
        res -= get(1, 0, 0, i, -1);

        if ( res > 0 ) { cout << i << ' ' << res << '\n'; return; }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
