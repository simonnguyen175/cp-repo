#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pi pair<ull, int>
using namespace std;
const int N = 3e6;
const ll oo = 1e19 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(isprime, 1, sizeof isprime);
    isprime[1] = 0;
    for (int i = 2; i*i < N; i ++) if ( isprime[i] )
    for (int j = i*i; j < N; j += i)
        isprime[i] = 0;
    for (int i = 2; i < N; i ++) if ( isprime[i] )
        prime.pb(i);

    for (int i = 1; i * i < N; i ++)
    for (int j = i*i; j < N; j += i)
        cnt[j] += 2;
    for (int i = 1; i * i < N; i ++) cnt[i] --;

    for (int i = 1; i < N; i ++){
        ull tmp = Pow(i, cnt[i]);
        if ( tmp != oo ) cont.pb({tmp, i});
    }
    sort(cont.begin(), cont.end());

    int test;
    while ( test -- ){
        ull e;
        cin >> e;
        ll res = -1;
        ll x = sqrt(e);
        if ( x * x == e && nto(x) ) res = x;

        int id = lower_bound(cont.begin(), cont.end(), {e, 0}) - cont.begin();
        if ( id < cont.size() && cont[id].fi == e )
            ( res == -1 || res > cont[id].se ) res = cont[id].se;

        cout << res << '\n';
    }

    return 0;
}
