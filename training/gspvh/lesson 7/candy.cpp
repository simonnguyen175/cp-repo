#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5;
const ll oo = 1e18;

int n, m;
ll A, B;
ll x[N], s[N], L = 1, sum = 0, g[N], st[4*N], F;

void update(int id, int l, int r, int u, ll v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = v;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("candy.inp", "r") ){
        freopen("candy.inp", "r", stdin);
        freopen("candy.out", "w", stdout);
    }

    cin >> n >> m >> A >> B;
    for (int i = 1; i <= n; i ++)
        cin >> x[i];

    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + x[i];

    for (int i = 1; i <= 4*n; i ++)
        st[i] = oo;

    g[0] = 0;
    update(1, 0, n, 0, 0);

    for (int i = 1; i <= n; i ++){
        sum += x[i];
        while ( sum > m && L < i )
            sum -= x[L], L ++;

        if ( sum > m ) F = g[i-1] + A * (s[i]-m);
        else{
            F = get(1, 0, n, L-1, i-1) + B * (m-s[i]);
            if ( L > 1 ) F = min(F,  g[L-2] + A*(s[i]-m));
        }

        update(1, 0, n, i, F + s[i] * B);

        g[i] = min(g[i-1], F - s[i] * A);
    }

    cout << F;

    return 0;
}
