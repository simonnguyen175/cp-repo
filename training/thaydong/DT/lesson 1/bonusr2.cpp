#include<bits/stdc++.h>
#define simon "bonusr2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e3 + 1;
const ll oo = 1e15;

int m, n;

namespace sub3{
    int a[N];
    ll f[N][N], mx[N], mn[N], ans = 0;

    void solve(){
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i ++)
            mx[i] = f[i][0] = a[i];

        for (int d = 1; d < n; d ++){
            for (int i = 1; i <= n; i ++){
                if ( i - d >= 1 ) f[i][d] = max(f[i][d], mx[i-d] + a[i]);
                if ( i + d <= n ) f[i][d] = max(f[i][d], mx[i+d] + a[i]);
            }
            for (int i = 1; i <= n; i ++)
                mx[i] = max(mx[i], f[i][d]);
        }
        for (int i = 1; i <= n; i ++)
            ans = max(ans, mx[i]);

        memset(f, 0x3ffffff, sizeof f);
        for (int i = 1; i <= n; i ++)
            mn[i] = f[i][0] = a[i];

        for (int d = 1; d < n; d ++){
            for (int i = 1; i <= n; i ++){
                if ( i - d >= 1 ) f[i][d] = min(f[i][d], mn[i-d] + a[i]);
                if ( i + d <= n ) f[i][d] = min(f[i][d], mn[i+d] + a[i]);
            }
            for (int i = 1; i <= n; i ++)
                mn[i] = min(mn[i], f[i][d]);
        }
        for (int i = 1; i <= n; i ++)
            ans = max(ans, abs(mn[i]));

        cout << ans;
    }
}

namespace sub4{
    int a[N][N], c[N*N];
    int cnt = 0, cnt1 = 0;
    pi pos[N*N];
    struct edge{
        int u, v;
        ll d;
        bool operator < (const edge& a) const{
            return d < a.d;
        }
    } edges[N*N];
    ll L[N*N], P[N*N];
    ll ans = 0;

    ll dis(pi a, pi b){
        return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
    }

    void init(){
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++){
                cin >> a[i][j];
                pos[++cnt] = {i, j};
                c[cnt] = a[i][j];
            }

        for (int i = 1; i <= cnt; i ++)
            for (int j = i + 1; j <= cnt; j ++)
                if ( i != j )
                    edges[++cnt1] = {i, j, dis(pos[i], pos[j])};

        sort(edges + 1, edges + 1 + cnt1);
    }

    void solve(){
        init();

        // MIN
        for (int i = 1; i <= cnt; i ++) P[i] = c[i];
        memset(L, 0, sizeof L);
        for (int i = 1; i <= cnt1; i ++){
            int u, v;
            // update L
            while ( edges[i].d == edges[i+1].d ){
                u = edges[i].u, v = edges[i].v;
                L[u] = min(L[u], P[v] + c[u]);
                L[v] = min(L[v], P[u] + c[v]);
                i ++;
            }
            u = edges[i].u, v = edges[i].v;
            L[u] = min(L[u], P[v] + c[u]);
            L[v] = min(L[v], P[u] + c[v]);

            // update P
            int j = i;
            while ( edges[j].d == edges[j-1].d ){
                u = edges[j].u, v = edges[j].v;
                P[u] = min(P[u], L[u]);
                P[v] = min(P[v], L[v]);
                j --;
            }
            u = edges[j].u, v = edges[j].v;
            P[u] = min(P[u], L[u]);
            P[v] = min(P[v], L[v]);
            //cout << i << '\n';
        }
        for (int i = 1; i <= cnt; i ++)
            ans = max(ans, abs(P[i]));

        //cout << ans << '\n';
        // MAX
        for (int i = 1; i <= cnt; i ++) P[i] = c[i];
        memset(L, 0, sizeof L);
        for (int i = 1; i <= cnt1; i ++){
            int u, v;
            // update L
            while ( edges[i].d == edges[i+1].d ){
                u = edges[i].u, v = edges[i].v;
                L[u] = max(L[u], P[v] + c[u]);
                L[v] = max(L[v], P[u] + c[v]);
                i ++;
            }
            u = edges[i].u, v = edges[i].v;
            L[u] = max(L[u], P[v] + c[u]);
            L[v] = max(L[v], P[u] + c[v]);

            // update P
            int j = i;
            while ( edges[j].d == edges[j-1].d ){
                u = edges[j].u, v = edges[j].v;
                P[u] = max(P[u], L[u]);
                P[v] = max(P[v], L[v]);
                j --;
            }
            u = edges[j].u, v = edges[j].v;
            P[u] = max(P[u], L[u]);
            P[v] = max(P[v], L[v]);
        }
        for (int i = 1; i <= cnt; i ++) ans = max(ans, P[i]);

        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;

    //if ( m == 1 ) sub3::solve();
    sub4::solve();

    return 0;
}
