#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int a, b, m;
vector<pi> way[2];
map<pi, int> id;
int t[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> a >> b >> m;

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        way[0].pb({u, v});
        way[1].pb({v, u});
        id[{u, v}] = i;
    }

    sort(way[0].begin(), way[0].end());
    sort(way[1].begin(), way[1].end());

    int x = 0, y = 0;
    int ans = a + b;

    while ( x < way[0].size() && y < way[1].size() ){
        int u = way[0][x].fi, d = way[1][x].fi;
        int uu = way[1][y].se, dd = way[0][x].se;

        t[id[way[0][x]]] = 1;

        while ( true ){
            bool ck = 0;

            if ( x < way[0].size() && way[0][x].fi <= uu ){
                if ( dd < way[0][x].se ) t[id[way[0][x]]] = 1;
                dd = max(dd, way[0][x].se);
                x ++;
                ck = 1;
            }

            if ( y < way[1].size() && way[1][y].fi <= dd ){
                uu = max(uu, way[1][y].se);
                y ++;
                ck = 1;
            }

            if ( !ck ) break;
        }

        if ( uu == u && dd == d ) continue;
        if ( uu == u ) t[id[{u, d}]] = 0;
        if ( dd == d ) t[id[{u, d}]] = 1;

//        cerr << u << ' ' << uu << " & " << d << ' ' << dd << '\n';

        ans -= ( uu - u + 1 ) + ( dd - d + 1 ) - 1;
    }

    cout << ans << '\n';
    for (int i = 1; i < m; i ++)
        cout << t[i] << ' ';
    cout << t[m] << '\n';

    return 0;
}
