#include<bits/stdc++.h>
#define simon "pawns"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e6;

int n, smask, fmask;
int a[15], mu3[15], vis[N], d[N];
pair<int, int> trace[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    mu3[0] = 1;
    for (int i = 1; i <= n; i ++)
        mu3[i] = mu3[i-1] * 3;

    int w = 0, b = 0;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        smask += ( x * mu3[i-1] );
        if ( x == 1 ) fmask += mu3[w++];
        if ( x == 2 ) fmask += 2*mu3[n-(++b)];
    }

    queue<int> q; d[smask] = 0; q.push(smask);

    while ( q.size() ){
        int u = q.front(); q.pop();
        if ( u == fmask ) break;
        int tmp = u;
        for (int i = 1; i <= n; i ++)
            a[i] = tmp % 3, tmp /= 3;

        for (int i = 1; i <= n; i ++){
            // white move
            if ( a[i] == 1 ){
                if ( i >= 2 && !a[i-1] ){
                    int v = u - mu3[i-1] + mu3[i-2];
                    if ( !vis[v] ){
                        d[v] = d[u] + 1;
                        vis[v] = 1;
                        trace[v].second = i; trace[v].first = u;
                        q.push(v);
                    }
                }
                if ( i >= 3 && !a[i-2] && a[i-1] ){
                    int v = u - mu3[i-1] + mu3[i-3];
                    if ( !vis[v] ){
                        d[v] = d[u] + 1;
                        vis[v] = 1;
                        trace[v].second = i; trace[v].first = u;
                        q.push(v);
                    }
                }
            }

            // black move
            if ( a[i] == 2 ){
                if ( i <= n - 1 && !a[i+1] ){
                    int v = u - 2*mu3[i-1] + 2*mu3[i];
                    if ( !vis[v] ){
                        d[v] = d[u] + 1;
                        vis[v] = 1;
                        trace[v].second = i; trace[v].first = u;
                        q.push(v);
                    }
                }
                if ( i <= n - 2 && !a[i+2] && a[i+1] ){
                    int v = u - 2*mu3[i-1] + 2*mu3[i+1];
                    if ( !vis[v] ){
                        d[v] = d[u] + 1;
                        vis[v] = 1;
                        trace[v].second = i; trace[v].first = u;
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << d[fmask] << '\n';
    vector<int> way;
    while ( trace[fmask].second ){
        //cout << fmask << " <- " << trace[fmask].second << "move " << trace[fmask].first << '\n';
        way.push_back(trace[fmask].second);
        fmask = trace[fmask].first;
    }
    reverse(way.begin(), way.end());
    for (auto u : way) cout << u << ' ';

    return 0;
}
