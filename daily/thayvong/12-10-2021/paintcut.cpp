#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e9;

int n, m, t, k;
int a[N][N], pre1[N], pre2[N], suf1[N], suf2[N];
struct row{
    int Premn[N], Premx[N], Sufmn[N], Sufmx[N];
} rows[N];

bool cmp(row a, row b){
    return a.Premx[k] < b.Premx[k];
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        rows[i].Premn[0] = rows[i].Sufmn[m+1] = oo;
        rows[i].Premx[0] = rows[i].Sufmx[m+1] = 0;
        for (int j = 1; j <= m; j ++){
            cin >> a[i][j];
            rows[i].Premn[j] = min(rows[i].Premn[j-1], a[i][j]);
            rows[i].Premx[j] = max(rows[i].Premx[j-1], a[i][j]);
        }
        for (int j = m; j >= 1; j --){
            rows[i].Sufmn[j] = min(rows[i].Sufmn[j+1], a[i][j]);
            rows[i].Sufmx[j] = max(rows[i].Sufmx[j+1], a[i][j]);
        }
    }

    bool ck = 0;
    for (k = 1; k < m; k ++){
        if ( ck ) break;
        sort(rows + 1, rows + 1 + n, cmp);

        pre1[0] = suf2[m+1] = 0;
        pre2[0] = suf1[m+1] = oo;

        for (int i = 1; i <= n; i ++){
            pre1[i] = max(pre1[i-1], rows[i].Premx[k]);
            pre2[i] = min(pre2[i-1], rows[i].Sufmn[k+1]);
        }

        for (int i = n; i >= 1; i --){
            suf1[i] = min(suf1[i+1], rows[i].Premn[k]);
            suf2[i] = max(suf2[i+1], rows[i].Sufmx[k+1]);
        }

        for (int i = 1; i < n; i ++)
            if ( pre1[i] < suf1[i+1] && pre2[i] > suf2[i+1] ) { ck = 1; break; }
    }

    if ( ck ) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("paintcut.inp", "r") ){
        freopen("paintcut.inp", "r", stdin);
        freopen("paintcut.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
