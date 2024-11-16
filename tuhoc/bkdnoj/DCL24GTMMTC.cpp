#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n;
int a[N], mn[N], mx[N], lef[N], rig[N];
vector<int> g[N];

void build(int u, int v){
    if ( a[v] < a[u] ){
        if ( !lef[u] ){
            lef[u] = v;
            g[u].push_back(v);
            g[v].push_back(u);
            return;
        }
        else build(lef[u], v);
    }
    else{
        if ( !rig[u] ){
            rig[u] = v;
            g[u].push_back(v);
            g[v].push_back(u);
            return;
        }
        else build(rig[u], v);
    }
}

void dfs(int u, int pu){
//    cout << u << ' ' << pu << '\n';
    for (int v : g[u]) if ( v != pu ){
        mn[v] = min(mn[u], a[v]);
        mx[v] = max(mx[u], a[v]);
//        cout << v << ' ' <<mn[u] << ' '<< mn[v] << ' ' << mx[v] << '\n';
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 2; i <= n; i ++){
        build(1, i);
    }

    int A, B;
    cin >> A >> B;
    int u, v;
    for (int i = 1; i <= n; i ++){
        if ( a[i] == A ) u = i;
        if ( a[i] == B ) v = i;
        mn[i] = oo;
        mx[i] = -oo;
    }
    mn[u] = mx[u] = a[u];
    dfs(u, 0);
    cout << mn[v] << ' ' << mx[v];

    return 0;
}
