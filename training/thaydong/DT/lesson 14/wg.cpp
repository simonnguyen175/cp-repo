#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int oo = 1e9;

string s;
int n, m;
int w[1005], e[1005], d[255][30], nxt[255][1005];
vector<int> g[30];
struct node{
    int l, c, dlc;
    bool operator > (const node &a) const{
        return dlc > a.dlc;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> n;
    m = s.size();
    s = ' ' + s;

    for (int i = 0; i <= m; i ++)
    for (int c = 0; c <= 25; c ++)
        d[i][c] = oo;

    for (int i = 1; i <= n; i ++){
        string t;
        cin >> t;

        w[i] = t.size()-1;
        g[t.front()-'a'].pb(i);
        e[i] = t.back()-'a';

        int cur = 0;
        for (int j = 0; j < t.size(); j ++) if ( t[j] == s[cur+1] )
            cur ++;
        if ( cur ) d[cur][e[i]] = min(d[cur][e[i]], w[i]+1);

        for (int j = 1; j < m; j ++){
            cur = j;
            for (int k = 1; k < t.size(); k ++) if ( t[k] == s[cur+1] ){
                cur ++;
                if ( cur == m ) break;
            }
            nxt[j][i] = cur;
        }
    }

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 0; i <= m; i ++)
    for (int c = 0; c <= 25; c ++) if ( d[i][c] != oo )
        heap.push({i, c, d[i][c]});

    int ans = oo;
    while ( heap.size() ){
        int l = heap.top().l, c = heap.top().c, dlc = heap.top().dlc;
        heap.pop();

        if ( l == m ){
            ans = min(ans, dlc);
            continue;
        }

        if ( dlc != d[l][c] ) continue;

        for (int x : g[c]){
            int nl = nxt[l][x], nc = e[x];
            if ( d[nl][nc] > dlc + w[x] ){
                d[nl][nc] = dlc + w[x];
                heap.push({nl, nc, d[nl][nc]});
            }
        }
    }

    if ( ans == oo ) cout << -1;
    else cout << ans;

    return 0;
}
