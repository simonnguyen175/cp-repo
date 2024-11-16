#include<bits/stdc++.h>
#define simon "wbrack2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

ll n, k;
map<int, ll> f[250][2];
string ans = "";

ll calc(int id, int ok, int sum){
    if ( f[id][ok].count(sum) ) return f[id][ok][sum];
    if ( id > n ){
        f[id][ok][sum] = ( ok ? 1 : 0 );
        return f[id][ok][sum];
    }

    ll res = 0, tmp;
    int open = ( id - 1 + sum ) / 2;
    int close = id - 1 - open;

    if ( open < n/2 ){
        tmp = calc(id + 1, ok, sum+1);
        if ( res + tmp > 1e18 ) res = 2e18;
        else res += tmp;
    }

    if ( close < n/2 ){
        tmp = calc(id + 1, ok | (sum-1<0), sum-1);
        if ( res + tmp > 1e18 ) res = 2e18;
        else res += tmp;
    }

    f[id][ok][sum] = res;

    return res;
}

void get(int id, int ok, int sum){
    //cout << " -> " << id << ' ' << ok << ' ' << sum << '\n';

    if ( id > n ) return;

    int open = ( id - 1 + sum ) / 2;
    int close = id - 1 - open;

    //cout << open << ' ' << close << '\n';

    if ( open < n/2 ){
        if ( f[id+1][ok][sum+1] >= k )
            ans += '(', get(id+1, ok, sum+1), k = 0;
        else k -= f[id+1][ok][sum+1];
    }

    if ( close < n/2 && k > 0 ){
        ans += ')';
        get(id+1, ok|(sum-1<0), sum-1);
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    n *= 2;

    calc(1, 0, 0);

    //cout << f[1][0][0] << '\n';

    get(1, 0, 0);

    cout << ans;

    return 0;
}
