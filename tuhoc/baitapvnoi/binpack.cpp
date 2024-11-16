#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e15;

int n, l, a[N];

namespace sub1{
    ll ans = oo;
    int b[25];

    void xuli(){
        ll tmp = 0;
        int bin1 = 0, bin2 = 0;
        for (int i = 1; i <= n; i ++)
            if ( !b[i] ){
                if ( bin1 + a[i] > l ) bin1 = a[i], tmp ++;
                else bin1 += a[i];
            }
            else{
                if ( bin2 + a[i] > l ) bin2 = a[i], tmp ++;
                else bin2 += a[i];
            }

        if ( bin1 ) tmp ++; if ( bin2 ) tmp ++;
        ans = min(ans, tmp);
    }

    void gen(int id){
        for (int i = 0; i <= 1; i ++){
            b[id] = i;
            if ( id == n ) xuli();
            else gen(id+1);
        }
    }

    void solve(){
        gen(1);
        cout << ans;
    }
}

namespace sub2{
    void solve(){
        ll s = 0;
        for (int i = 1; i <= n; i ++) s += a[i];
        ll ans = s / 100 + ( s % 100 != 0 );
        cout << ans;
    }
}

namespace subAC{
    void solve(){
        ll ans = oo;
        pi f[2][5001];

        for (int j = 1; j <= l; j++) f[1][j] = f[0][j] = {oo, 0};

        f[0][l] = {0 , l};

        for (int i = 0; i < n; i++){
            for (int k = 1; k <= l; k++) f[1 - i % 2][k] = {oo, 0};

            for (int j = 1 ; j <= l; j++){
                if ( f[i % 2][j].fi == oo ) continue;

                ll res = f[i % 2][j].fi , w2 = f[i % 2][j].se , w1 = j;

                // use bin2
                if ( w2 + a[i + 1] > l ) res ++, w2 = a[i + 1] ;
                else w2 += a[i + 1];
                if ( res < f[1 - i % 2][j].fi || (res == f[1 - i % 2][j].fi && f[1 - i % 2][j].se > w2) ) f[1 - i % 2][j] = {res , w2};

                // use bin1
                res = f[i % 2][j].fi;
                if ( w1 + a[i + 1] > l ) res ++,  w1 = a[i + 1] ;
                else w1 += a[i + 1];
                if ( res < f[1 - i % 2][w1].fi || (res == f[1 - i % 2][w1].fi && f[1 - i % 2][w1].se > f[i % 2][j].se) ) f[1 - i % 2][w1] = {res , f[i % 2][j].se};
            }
        }

        for (int i = 1 ; i <= l ; i++) ans = min(f[n % 2][i].fi , ans);

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> l >> n;

    int flag = 1;

    for (int i = 1; i <= n; i++) { cin >> a[i]; if ( a[i] > 2 ) flag = 0; }

    if ( n <= 20 ) sub1::solve();
        else if ( l == 100 && flag ) sub2::solve();
            else subAC::solve();

    return 0;
}
