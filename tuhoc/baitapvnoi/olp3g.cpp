#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n;
int c[N], Par[N], Size[N];
ll ans = 0;
struct edg{
    int u, v, w;
} ed1[N], ed2[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return u = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Size[u] < Size[v] ) swap(u, v);
        Par[v] = u;
        Size[u] += Size[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v;

        w = max(c[u], c[v]);
        ed1[i] = {u, v, w};

        w = min(c[u], c[v]);
        ed2[i] = {u, v, w};
    }

    for (int i = 1; i <= n; i ++) Par[i] = i, Size[i] = 1;
    sort(ed1+1, ed1+n, [](edg a, edg b){
        return a.w < b.w;
    });
    for (int i = 1; i < n; i ++){
        ans += 1LL * ed1[i].w * ( 1LL * Size[Find(ed1[i].u)] * Size[Find(ed1[i].v)] );
        Join(ed1[i].u, ed1[i].v);
    }

    for (int i = 1; i <= n; i ++) Par[i] = i, Size[i] = 1;
    sort(ed2+1, ed2+n, [](edg a, edg b){
        return a.w > b.w;
    });
    for (int i = 1; i < n; i ++){
        ans -= 1LL * ed2[i].w * ( 1LL * Size[Find(ed2[i].u)] * Size[Find(ed2[i].v)] );
        Join(ed2[i].u, ed2[i].v);
    }

    cout << ans;

    return 0;
}
