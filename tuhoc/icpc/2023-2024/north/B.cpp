#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int idx(int x){
    return upper_bound(contx.begin(), contx.end(), x) - contx.begin();
}

int idy(int y){
    return upper_bound(conty.begin(), conty.end(), y) - conty.begin();
}

void update(int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].se += val;
        if ( st[id].se ) st[id].fi += conty[r-1] - conty[l-1];
        else if ( l != r ) st[id].fi = st[id*2].fi + st[id*2+! ]
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> k >> n;
    pi cur = {0, 0};

    cont.pb({{0, 0}, {k, k}});

    for (int i = 1; i <= n; i ++){
        char dir;
        int x;
        cin >> dir >> x;
        if ( dir == 'N' ){
            cont.pb({{cur.fi, cur.se + k}, {cur.fi + k, cur.se + x + k}});
            cur.se += x;
        }

        if ( dir == 'W' ){
            cont.pb({{cur.fi - x, cur.se}, {cur.fi - x + k, cur.se + k}});
            cur.fi -= x;
        }

        if ( dir == 'S' ) {
            cont.pb({cur.fi, cur.se - x}, {cur.fi + k, cur.se});
            cur.se -= x;
        }

        if ( dir == 'E' ){
            cont.pb({cur.fi + k, cur.se}, {cur.fi + x + k, cur.se + k});
            cur.fi += x;
        }
    }

    for (auto it : cont){
        contx.pb(it.fi.fi), contx.pb(it.se.fi);
        conty.pb(it.fi.se), conty.pb(it.se.se);
    }

    sort(contx.begin(), contx.end());
    contx.erase(unique(contx.begin(), contx.end()), contx.end());

    sort(conty.begin(), conty.end());
    conty.erase(unique(conty.begin(), conty.end()), conty.end());

    sort(cont.begin(), cont.end());


    return 0;
}
