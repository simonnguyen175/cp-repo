#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int v, n, m;
int p[25], b[5], f[(1<<15)+5][25], vis[(1<<15)+5][25];

int main(){
    cin >> v >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    for (int i = 0; i <= v; i ++)
        for (int j = 0; j <= n; j ++)
            f[i][j] = INT_MAX;

    f[v][0] = 0; vis[v][0] = 1;
    queue<pi> q; q.push({v, 0});

    while ( q.size() ){
        int fu = f[q.front().fi][q.front().se];

        b[1] = q.front().fi;
        b[2] = p[q.front().se];
        b[3] = v - b[1] - b[2];
        q.pop();



        for (int u = 1; u <= 3; u ++)
        for (int v = 1; v <= 3; v ++){
            if ( u == v ) continue;
            // binh u -> binh v

            // binh u cham vach
            for (int i = 0; p[i] < b[u] && i <= n; i ++){
                int nuoc, vach;
                nuoc = b[v] + b[u] - p[i];
                vach = i;
                if ( vis[nuoc][vach] ) continue;
                f[nuoc][vach] = fu + 1;
                vis[nuoc][vach] = 1;
                q.push({nuoc, vach});
            }

            // binh v cham vach
            for (int i = n; p[i] > b[v] && i >= 1; i --){
                int nuoc, vach;
                if ( b[u] - ( p[i] - b[v] ) < 0 ) continue;
                nuoc = b[u] - ( p[i] - b[v] );
                vach = i;
                if ( vis[nuoc][vach] ) continue;
                f[nuoc][vach] = fu + 1;
                vis[nuoc][vach] = 1;
                q.push({nuoc, vach});
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= v; i ++)
    for (int j = 0; j <= n; j ++)
        if ( i == m || p[j] == m || v - i - p[j] == m )
            ans = min(ans, f[i][j]);

    cout << ( ans == INT_MAX ? -1 : ans );

    return 0;
}
