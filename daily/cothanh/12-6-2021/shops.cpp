#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

ll n, S;
ll s[N], mx[N];
pi cont[N], ans;

int get(ll x){
    int lo = 1, hi = n, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( cont[mid].fi <= x ){
            res = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("shops.inp", "r", stdin);
    freopen("shops.out", "w", stdout);


    cin >> n >> S;
    for (int i = 1; i <= n; i ++)
        cin >> s[i], s[i] += s[i-1], cont[i] = {s[i], i};
    sort(cont + 1, cont + 1 + n);

    for (int i = 1; i <= n; i ++)
        mx[i] = max(cont[i].se, mx[i-1]);

    for (int i = 1; i <= n; i ++){
        int pos = mx[get(S + s[i-1])];
        if ( pos - i + 1 > ans.fi ){
            ans.fi = pos - i + 1;
            ans.se  = i;
        }
    }

    cout << ans.fi << ' ' << ans.se;

    return 0;
}
