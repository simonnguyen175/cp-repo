#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int k, ans;
int a[N], b[N], pw2[N], c1[2*N], c2[2*N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> k;
    for (int i = 1; i <= k; i ++) cin >> a[i];
    for (int i = 1; i <= k; i ++) cin >> b[i];

    for (int i = 1; i <= k; i ++) ans = add(ans, a[i]-1);

    for (int i = 1; i <= k; i ++) a[i] -= b[i];
    for (int i = 1; i <= k; i ++){
        b[i] --;
        if ( a[i] > b[i] ) swap(a[i], b[i]);
    }

    vector<int> cont;
    for (int i = 1; i <= k; i ++)
        cont.pb(a[i]), cont.pb(b[i]);

    cont.pb(0);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 1; i <= k; i ++){
        a[i] = lower_bound(cont.begin(), cont.end(), a[i]) - cont.begin();
        b[i] = lower_bound(cont.begin(), cont.end(), b[i]) - cont.begin();

        c2[1] ++; c2[a[i]+1] --;
        c1[a[i]+1] ++; c1[b[i]+1] --;
    }

    pw2[0] = 1;
    for (int i = 1; i <= k; i ++)
        pw2[i] = mul(pw2[i-1], 2);

    for (int i = 1; i < cont.size(); i ++){
        c1[i] += c1[i-1];
        c2[i] += c2[i-1];
        if ( c1[i] + c2[i] == k )
            ans = add(ans, mul(cont[i]-cont[i-1], pw2[c2[i]]));
    }

    cout << ans;

    return 0;
}
