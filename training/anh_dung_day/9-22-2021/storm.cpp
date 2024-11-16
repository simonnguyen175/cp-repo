#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

int t, n, q;
ll h[N], s[N];
pair<int, ll> paru[N][25], pard[N][25];

void init(){
    cin >> n >> q;

    for (int i = 1; i <= n; i ++){
        cin >> h[i];
        s[i] = s[i-1] + h[i];
    }

    deque<ll> dq;
    for (int i = n; i >= 1; i --){
        while ( dq.size() && h[dq.back()] < h[i] ) dq.pop_back();
        if ( dq.size() )
            paru[i][1].fi = dq.back(), paru[i][1].se = ((dq.back()-i-1)*h[i]-s[dq.back()-1]+s[i])%MOD;
        else paru[i][1].fi = n + 1, paru[i][1].se = 0;
        dq.push_back(i);
    }

    dq.clear();
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && h[dq.back()] <= h[i] ) dq.pop_back();
        if ( dq.size() )
            pard[i][1].fi = dq.back(), pard[i][1].se = ((i-dq.back()-1)*h[i]-s[i-1]+s[dq.back()])%MOD;
        else pard[i][1].fi = 0, pard[i][1].se = 0;
        dq.push_back(i);

    }
    paru[n+1][1].fi = n + 1;
    pard[0][1].fi = 0;

    for (int j = 2; j <= log2(n); j ++)
    for (int i = 0; i <= n; i ++){
        pard[i][j].fi = pard[pard[i][j-1].fi][j-1].fi;
        pard[i][j].se = (pard[i][j-1].se+pard[pard[i][j-1].fi][j-1].se)%MOD;
    }

    for (int j = 2; j <= log2(n); j ++)
    for (int i = n + 1; i >= 1; i --){
        paru[i][j].fi = paru[paru[i][j-1].fi][j-1].fi;
        paru[i][j].se = (paru[i][j-1].se+paru[paru[i][j-1].fi][j-1].se)%MOD;
    }
}

void solve(){
    ll ans = 0;
    for (int i = 1; i <= q; i ++){
        int l, r; cin >> l >> r;
        int fl = l, fr = r;

        for (int j = log2(n); j >= 1; j --){
            if ( paru[l][j].fi <= fr ) ans = (ans+paru[l][j].se)%MOD, l = paru[l][j].fi;
            if ( pard[r][j].fi >= fl ) ans = (ans+pard[r][j].se)%MOD, r = pard[r][j].fi;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;

    while ( t -- ){
        init();
        solve();
    }

    return 0;
}
