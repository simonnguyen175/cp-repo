#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, G, m;
int f[N], g[N], ans[N];
pair<char, int> a[N];
int d[2][N];
queue<int> q;

void upd(int t, int p){
    d[t][p] ++;
}

int add(int a, int b){
    a += b;
    if ( a >= n ) a -= n;
    if ( a < 0 ) a += n;
    return a;
}

void solve(){
    cin >> n >> G >> m;
    for (int i = 0; i < n; i ++) f[i] = g[i] = oo, d[0][i] = d[1][i] = 0;
    for (int i = 1; i <= G; i ++) ans[i] = 0;
    for (int i = 1; i <= G; i ++){
        char t;
        int p;
        cin >> p >> t;
        p --;
        if ( t == 'C' ){
            p = add(p, m%n);
            f[p] = 0;
            a[i] = {t, p};
        }
        if ( t == 'A' ){
            p = add(p, -(m%n));
            g[p] = 0;
            a[i] = {t, p};
        }
    }

    for (int i = 0; i < n; i ++)
        if ( f[i] != oo ){
            q.push(i);
        }
    while ( q.size() ){
        int u = q.front();
        q.pop();

        if ( f[u] == m ) continue;

        int v = add(u, -1);
        if ( f[v] == oo ) f[v] = f[u] + 1, q.push(v);
    }

    for (int i = 0; i < n; i ++)
        if ( g[i] != oo ){
            q.push(i);
        }

    while ( q.size() ){
        int u = q.front();
        q.pop();

        if ( g[u] == m ) continue;

        int v = add(u, 1);
        if ( g[v] == oo ) g[v] = g[u] + 1, q.push(v);
    }

    for (int i = 0; i < n; i ++){
        int u = add(i, f[i]%n);
        int d = add(i, -(g[i]%n));
        if ( f[i] < g[i] ) upd(0, u);
        else if ( f[i] > g[i] ) upd(1, d);
        else if ( f[i] != oo ){
            upd(0, u);
            upd(1, d);
        }
    }

    for (int i = 1; i <= G; i ++)
        if ( a[i].fi == 'C' ) cout << d[0][a[i].se] << ' ';
        else cout << d[1][a[i].se] << ' ';

    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
