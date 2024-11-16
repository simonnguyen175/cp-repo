#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
ll ans = 0;
ll a[N], st[N], ed[N];
ll sp[N][18], Log[N];

void init(){
    // deque max
    deque<ll> dq;
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && a[i] >= a[dq.back()] )
            dq.pop_back();
        if ( dq.size() ) st[i] = dq.back() + 1;
        else st[i] = 1;
        dq.push_back(i);
    }
    dq.clear();
    for (int i = n; i >= 1; i --){
        while ( dq.size() && a[i] > a[dq.back()] )
            dq.pop_back();
        if ( dq.size()) ed[i] = dq.back() - 1;
        else ed[i] = n;
        dq.push_back(i);
    }

    // sparse table gcd
    Log[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i/2] + 1;
    for (int i = 1; i <= n; i ++)
        sp[i][0] = a[i];
    for (int j = 1; j <= Log[n]; j ++)
        for (int i = 1; i + (1 << j) - 1 <= n; i ++)
            sp[i][j] = __gcd(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
}

ll get(ll u, ll v){
    ll l = Log[v-u+1];
    return __gcd(sp[u][l], sp[v-(1<<l)+1][l]);
}

void solve(){
    for (ll i = 1; i <= n; i ++){
        vector<ll> L, R;
        L.push_back(i); R.push_back(i);

        while ( R[R.size()-1] != ed[i] ){
            ll x = get(i, R[R.size()-1] + 1);
            ll d = R[R.size()-1] + 1, c = ed[i], res;
            while ( d <= c ){
                ll mid = ( d + c ) / 2;
                if ( get(i, mid) == x ) res = mid, d = mid + 1;
                else c = mid - 1;
            }
            R.push_back(res);
        }

        while ( L[L.size() - 1] != st[i] ){
            ll x = get(L[L.size() - 1] - 1 , i);
            ll d = st[i], c = L[L.size() - 1] - 1, res;
            while ( d <= c ){
                ll mid = (d + c) / 2;
                if ( get(mid, i) == x ) res = mid, c = mid - 1;
                else d = mid + 1;
            }
            L.push_back(res);
        }

        for(int t = 0; t < L.size(); t ++)
        for(int k = 0; k < R.size(); k ++) {
             ll len1, len2;
             if ( t == 0 ) len1 = 1;
             else len1 = L[t - 1] - L[t];
             if ( k == 0 ) len2 = 1;
             else len2 = R[k] - R[k - 1];
             ans += ( ( (len1 * len2) % MOD) * ((a[i] * get(L[t] , R[k])) % MOD) ) % MOD;
             ans %= MOD;
         }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    init();
    solve();

    return 0;
}
