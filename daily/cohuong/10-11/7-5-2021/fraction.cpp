#include<bits/stdc++.h>
#define simon "fraction"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, w, ans;
ii a[N], b[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

bool operator < (ii a, ii b){
    return ( a.fi * b.se ) < ( b.fi * a.se );
}

bool operator > (ii a, ii b){
    return ( a.fi * b.se ) > ( b.fi * a.se );
}

int tknp (int l, int r, ii x){
    int d = l, c = r, res = 0;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        if ( b[mid] < x ){
            res = mid;
            d = mid + 1;
        }
        else c = mid - 1;
    }
    return res;
}

int main(){
    file();
    cin >> n >> w;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        ll gcd = __gcd(a[i].fi, a[i].se);
        a[i].fi /= gcd; a[i].se /= gcd;
    }

    if ( w == 0 ){
        ans = 1;
        for (int i = 1; i <= n; i ++)
            b[i].fi = 1e9, b[i].se = 1;
        for (int i = 1; i <= n; i ++){
            int len = tknp(1, n, a[i]);
            if ( a[i] < b[len+1] ) b[len+1] = a[i];
            ans = max(ans, len + 1);
        }
        cout << ans;
    }
    if ( w == 1 ){
        ans = 1;
        for (int i = 1; i <= n; i ++)
            b[i].fi = 1e9, b[i].se = 1;
        for (int i = 1; i <= n; i ++){
            ii tmp; tmp.fi = a[i].se; tmp.se = a[i].fi;

            int len1 = tknp(1, ans, a[i]);
            int len2 = tknp(1, ans, tmp);

            if ( a[i] < b[len1+1] ) b[len1+1] = a[i];
            if ( tmp < b[len2+1] ) b[len2+1] = tmp;

            ans = max({ans, len1+1, len2+1});
        }
        cout << ans;
    }

    return 0;
}
