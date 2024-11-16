#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 4e6 + 5;

int n, nnode = 1;
string s;
int nxt[N], type[N], g[N][2];
pi rng[N];

void build(int id, int l){
    if ( s[l+1] == 'a' ) type[id] = 1;

    g[id][0] = ++nnode;
    int nl;
    if ( s[l+4] != '?' ){
        build(nnode, l+4);
        nl = nxt[l+4+3] + 2;
    }
    else{
        n ++;
        nl = l + 6;
    }

    g[id][1] = ++nnode;
    if ( s[nl] != '?' ) build(nnode, nl);
    else n ++;
}

void dfs(int u){
    if ( !g[u][0] ) { rng[u] = {1, 1}; return; }

    int l = g[u][0], r = g[u][1];

    dfs(l);
    dfs(r);

    if ( !type[u] ){
        rng[u].fi = min(rng[l].fi, rng[r].fi);
        rng[u].se = rng[l].se + rng[r].se;
    }
    else{
        rng[u].fi = rng[l].fi + rng[r].fi;
        rng[u].se = min(rng[l].se, rng[r].se);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> s;
    n = s.size();
    s = ' ' + s;
    stack<int> stk;
    for (int i = 1; i <= n; i ++){
        if ( s[i] != '(' && s[i] != ')' ) continue;
        if ( s[i] == ')' ){
            nxt[stk.top()] = i;
            stk.pop();
        }
        else stk.push(i);
    }

    n = 0;

    build(1, 1);

    dfs(1);

    cout << n - rng[1].se + 1 - rng[1].fi + 1;

    return 0;
}
