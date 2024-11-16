#include<bits/stdc++.h>
#define pi pair<int, char>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 50;
const string s = "GSPVHCUTE";

int n, m, k, cnt = 0;
vector<int> g[N];
pair<int, char> a[N];
char cur[N];
int rem[N];

void btrk(int id){
    for (int i = 1; i <= 9; i ++) if ( rem[i] ){
        bool ck = 1;
        for (int x : g[id])
            if ( cur[x] == a[i].se ) { ck = 0; break; }
        if ( !ck ) continue;

        rem[i] --;
        cur[id] = a[i].se;

        cnt ++;
        if ( cnt == k ){
            for (int j = 1; j <= id; j ++) cout << cur[j];
            exit(0);
        }
        if ( id < n ) btrk(id+1);

        rem[i] ++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("F.inp", "r") ){
        freopen("F.inp", "r", stdin);
        freopen("F.out", "w", stdout);
    }

    for (int i = 1; i <= 9; i ++){
        cin >> a[i].fi;
        a[i].se = s[i-1];
        n += a[i].fi;
    }
    sort(a + 1, a + 10, [&](pi b, pi c){
        return b.se < c.se;
    });
    for (int i = 1; i <= 9; i ++)
        rem[i] = a[i].fi;

    cin >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        if ( u < v ) swap(u, v);
        g[u].pb(v);
    }

    cin >> k;
    btrk(1);

    return 0;
}
