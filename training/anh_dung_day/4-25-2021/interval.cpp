#include<bits/stdc++.h>
#define simon "interval"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define l first
#define r second
using namespace std;
const int N=1e6+5;
const int oo=1e9;

int n, ans;
int st[20*N];
pair<int, int> a[N];

void update(int id, int l, int r, int i, int v){
    if ( i < l || r < i ){
        return;
    }
    if ( l == r ){
        st[id]=v;
        return;
    }
    int mid = (l + r)/2;
    update(id*2, l, mid, i, v);
    update(id*2+1, mid+1, r, i, v);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( v < l || r < u ){
        return 0;
    }
    if ( u <= l && r <= v ){
        return st[id];
    }
    int mid = (l + r)/2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].r*=-1;
    }
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++){
        a[i].r*=-1;
    }
    for (int i=1; i<=n; i++){
        int v = get(1, 0, N, a[i].r, N) + 1;
        update(1, 0, N, a[i].r, v);
    }
    for (int i=1; i<=20*N; i++) ans=max(ans, st[i]);
    cout << ans;
    return 0;
}
