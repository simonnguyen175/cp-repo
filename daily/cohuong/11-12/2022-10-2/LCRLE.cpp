#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

string x, y;
int na = 0, nb = 0;
pair<char, ll> a[N], b[N];
ll f[N][N], g[N][N], suma[N][26], sumb[N][26];

void init(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> x >> y;

    char c = x[0]; ll sl = 0;
    for (int i = 1; i < x.size(); i ++){
        if ( x[i] >= '0' && x[i] <= '9' )
            sl = sl*10 + (x[i]-'0');
        else{
            a[++na] = {c, sl};
            c = x[i];
            sl = 0;
        }
    }
    a[++na] = {c, sl};

    c = y[0]; sl = 0;
    for (int i = 1; i < y.size(); i ++){
        if ( y[i] >= '0' && y[i] <= '9' )
            sl = sl*10 + (y[i]-'0');
        else{
            b[++nb] = {c, sl};
            c = y[i];
            sl = 0;
        }
    }
    b[++nb] = {c, sl};

    for (int i = 1; i <= na; i ++)
        for (int j = 0; j <= 26; j ++){
            suma[i][j] = suma[i-1][j];
            if ( a[i].fi == 'a' + j ) suma[i][j] += a[i].se;
        }

    for (int i = 1; i <= nb; i ++)
        for (int j = 0; j <= 26; j ++){
            sumb[i][j] = sumb[i-1][j];
            if ( b[i].fi == 'a' + j ) sumb[i][j] += b[i].se;
        }

    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
}

void sub1(){
    // calc lcs
    ll lcs = 0;
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++)
            if ( a[i].fi == b[j].fi ){
                int c = a[i].fi - 'a';
                for (int i1 = i-1; i1 >= 0; i1 --)
                    for (int j1 = j-1; j1 >= 0; j1 --)
                        f[i][j] = max(f[i][j], f[i1][j1] + min(suma[i][c]-suma[i1][c], sumb[j][c]-sumb[j1][c]));
                lcs = max(lcs, f[i][j]);
            }

    // calc lccs
    ll lccs = 0;
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++)
            if ( a[i].fi == b[j].fi ){
                g[i][j] = min(a[i].se, b[j].se);
                if ( a[i].se == b[j].se )
                    g[i][j] = max(g[i][j], g[i-1][j-1] + a[i].se);
            }
            else g[i][j] = 0;

    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++){
            lccs = max(lccs, g[i][j] + (a[i+1].fi == b[j+1].fi) * min(a[i+1].se, b[j+1].se));
        }

    cout << lcs << '\n' << lccs << '\n';
}

void sub2(){
    // calc lcs
    ll lcs = 0;
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++)
            if ( a[i].fi == b[j].fi ){
                char c = a[i].fi;
                int i1, j1;
                ll sa, sb;

                // sa la min
                j1 = j - 1; i1 = i - 1;
                sa = a[i].se; sb = b[j].se;
                for (i1; i1 >= 0; i1 --){
                    while ( j1 > 0 && sb < sa ){
                        if ( b[j1].fi == c ) sb += b[j1].se;
                        j1 --;
                    }

                    if ( j1 == 0 ) {f[i][j] = max(f[i][j], f[i1][j1] + min(sa, sb)); lcs = max(lcs, f[i][j]); break;}
                    f[i][j] = max(f[i][j], f[i1][j1] + sa);
                    if ( a[i1].fi == c ) sa += a[i1].se;
                    lcs = max(lcs, f[i][j]);
                }

                // sb la min
                j1 = j - 1; i1 = i - 1;
                sa = a[i].se; sb =  b[j].se;
                for (j1; j1 >= 0; j1 --){
                    while ( i1 > 0 && sa < sb ){
                        if ( a[i1].fi == c ) sa += a[i1].se;
                        i1 --;
                    }

                    if ( i1 == 0 ) {f[i][j] = max(f[i][j], f[i1][j1] + min(sa, sb)); lcs = max(lcs, f[i][j]); break;}
                    f[i][j] = max(f[i][j], f[i1][j1] + sb);
                    if ( b[j1].fi == c ) sb += b[j1].se;
                    lcs = max(lcs, f[i][j]);
                }
            }
            else f[i][j] = max({f[i-1][j-1], f[i-1][j], f[i][j-1]});

    // calc lccs
    ll lccs = 0;
    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++)
            if ( a[i].fi == b[j].fi ){
                g[i][j] = min(a[i].se, b[j].se);
                if ( a[i].se == b[j].se )
                    g[i][j] = max(g[i][j], g[i-1][j-1] + a[i].se);
            }
            else g[i][j] = 0;

    for (int i = 1; i <= na; i ++)
        for (int j = 1; j <= nb; j ++){
            lccs = max(lccs, g[i][j] + (a[i+1].fi == b[j+1].fi) * min(a[i+1].se, b[j+1].se));
        }

    cout << lcs << '\n' << lccs << '\n';
}

int main(){
    freopen("LCRLE.inp", "r", stdin);
    freopen("LCRLE.out", "w", stdout);

    init();
    //if ( n <= 50 ) sub1();
    //else
    sub2();

    return 0;
}

