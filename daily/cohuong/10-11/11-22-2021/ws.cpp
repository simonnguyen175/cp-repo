#include<bits/stdc++.h>
#define simon "ws"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e6 + 5;

string s;
ll MOD;
ll cnt[30], numPow[N], lpf[N];

void sieve(){
    lpf[1] = 0;
    for (ll i = 2; i < N; i ++) lpf[i] = i;
    for (ll i = 2; i * i < N; i ++)
        if ( lpf[i] == i )
            for (ll j = i * i; j < N; j += i)
                lpf[j] = i;
}

void add(ll x, ll t){
    while ( lpf[x] ){
        numPow[lpf[x]] += t;
        x /= lpf[x];
    }
}

ll Pow(ll a, ll b){
	if ( b == 0 ) return 1;
	ll tmp = Pow(a, b / 2);
	tmp = tmp * tmp % MOD;
	if ( b % 2 ) return ( tmp * a ) % MOD;
	else return tmp;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    sieve();

    cin >> MOD >> s;

    for (int i = 1; i <= s.size(); i ++)
        add(i, 1);

    for (int i = 0; i < s.size(); i ++)
        cnt[s[i]-'a'] ++;

    for (int i = 0; i <= 27; i ++)
        for (int j = 1; j <= cnt[i]; j ++)
            add(j, -1);

    ll ans = 1;
    for (ll i = 1; i < N; i ++){
        for (ll j = 1; j <= numPow[i]; j ++)
            ans = ans * i % MOD;
    }

    cout << ans;

    return 0;
}
