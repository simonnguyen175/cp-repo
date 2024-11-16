#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
using namespace std;

int n, m;
vector<pair<int, int>> edges;
int pa0[10], fpa[10];
ll f[40][1][2][3][4][5][6][7][8][9];

ll cal(int t, int pa[]){
    //cout << t << '\n';
    //for (int i = 0; i <= 8; i ++) cout << pa[i] << ' ';
    //cout << '\n';

    if ( f[t][pa[0]][pa[1]][pa[2]][pa[3]][pa[4]][pa[5]][pa[6]][pa[7]][pa[8]] != - 1 )
        return f[t][pa[0]][pa[1]][pa[2]][pa[3]][pa[4]][pa[5]][pa[6]][pa[7]][pa[8]];

    if ( t == m ){
        int cnt = 0;
        for (int i = 0; i < n; i ++)
            if ( pa[i] == fpa[i] ) cnt ++;
        if ( cnt == n ) return 1;
        else return 0;
    }

    ll cnt = 0;

    // su dung canh t
    int pa1[9];
    for (int i = 0; i <= 8; i ++) pa1[i] = pa[i];
    int mi = min(pa1[edges[t].fi], pa1[edges[t].se]);
    int ma = max(pa1[edges[t].fi], pa1[edges[t].se]);
    for (int i = 0; i < n; i ++)
        if ( pa1[i] == ma ) pa1[i] = mi;

    cnt += cal(t+1, pa1);

    // ko su dung canh t
    cnt += cal(t+1, pa);

    f[t][pa[0]][pa[1]][pa[2]][pa[3]][pa[4]][pa[5]][pa[6]][pa[7]][pa[8]] = cnt;

    return cnt;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        u --; v --;
        edges.pb({u, v});
    }

    for (int i = 0; i <= 8; i ++) pa0[i] = fpa[i] = i;

    for (auto it : edges){
        int mi = min(fpa[it.fi], fpa[it.se]);
        int ma = max(fpa[it.fi], fpa[it.se]);

        for (int i = 0; i < n; i ++)
            if ( fpa[i] == ma ) fpa[i] = mi;
    }

    memset(f, -1, sizeof f);

    cout << cal(0, pa0);

    return 0;
}
