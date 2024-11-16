#include<bits/stdc++.h>
#define simon "grn2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int MOD = 111539786;

int n;
int a[N], d[N], lef[N], calc[N];
ll fact[N], C[N][N], f[N];
vector<int> b, cont, diffs;
map<int, int> id;
ll res = 0, ans = 0;

ll anal(int diff){
    //cout << diff << " : " << '\n';

    // th diff = 0
    if ( diff == 0 ){
        for (int i = 1; i <= n; i ++) d[i] = 0;
        for (int i = 1; i <= n; i ++)
            d[id[a[i]]] ++;
        res = 1;
        for (int i = 1; i <= n; i ++)
            if ( d[i] % 2 ) return 0;
            else res *= f[d[i]/2];
    }
    // th diff > 0
    else{
        b.clear();
        for (int i = 1; i <= n; i ++) d[i] = 0, lef[i] = 0;
        for (int i = 1; i <= n; i ++) d[id[a[i]]] ++;
        for (int i = 1; i <= n; i ++){
            if ( !d[id[a[i]]] ) continue;
            d[id[a[i]]] --;
            if ( !id.count(a[i]+diff) || !d[id[a[i]+diff]] ) return 0;
            d[id[a[i]+diff]] --;
            b.pb(a[i]); b.pb(a[i]+diff);
        }

        //for (auto x : b) cout << x << ' '; cout << '\n';

        for (int i = 1; i <= n; i ++) calc[i] = 0;

        int tt = 0;
        for (int i = 0; i < b.size(); i ++)
            if ( i % 2 == 0 ){
                if ( !d[id[b[i]]] ){
                    tt ++; if ( tt % 2 == 0 ) calc[id[b[i]]] = 1;
                }
                d[id[b[i]]] ++; lef[id[b[i]]] ++;
            }
            else{
                if ( !d[id[b[i]]] ){
                    tt ++; if ( tt % 2 == 0 ) calc[id[b[i]]] = 1;
                }
                d[id[b[i]]] ++;
            }

        res = 1;
        for (int i = 0; i < cont.size(); i ++){
            if ( !calc[i+1] ) ( res *= fact[d[i+1]] ) %= MOD;
            else ( res *= C[d[i+1]][lef[i+1]] ) %=MOD;
        }
    }

    //cout << res << '\n';

    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n; n *= 2;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    fact[0] = 1;
    for (int i = 1; i <= n; i ++)
        fact[i] = fact[i-1] * i % MOD;

    C[0][0] = 1;
    for (int i = 1; i <= n; i ++){
        C[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % MOD;
    }

    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i ++)
        diffs.pb(a[i] - a[1]);
    diffs.erase(unique(diffs.begin(), diffs.end()), diffs.end());

    for (int i = 1; i <= n; i ++)
        cont.pb(a[i]);
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    f[0] = 1;
    for (int i = 1; i <= n/2; i ++)
        f[i] = f[i-1] * (i*2-1) % MOD;

    for (int diff : diffs)
        ( ans += anal(diff) ) %= MOD;

    cout << ans;

    return 0;
}
