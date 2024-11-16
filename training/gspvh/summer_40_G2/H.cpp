#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e7 + 5;
const int M = 1e6 + 5;

ll n;
int a[M], lpf[N], primeset[M];
ll numPow[N];
bool isPrime[N];
int cnt = 0;

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = 0; lpf[1] = 0;
    for (int i = 2; i * i <= a[n]; i ++)
        if ( isPrime[i] )
            for (int j = i * i; j <= a[n]; j += i)
                isPrime[j] = 0, lpf[j] = i;
    for (int i = 2; i <= a[n]; i ++)
        if ( isPrime[i] ) lpf[i] = i, primeset[++cnt] = i;
}

void add(int x, int pos){
    while ( lpf[x] )
        numPow[lpf[x]] += n - pos + 1, x /= lpf[x];
}

ll cal(ll p, ll x){
    ll res = 0, tmp = p;
    while ( p <= x ){
        res += x / p;
        p *= tmp;
    }
    return res;
}

bool check(ll x){
    for (int i = 1; i <= cnt; i ++){
        if ( cal(primeset[i], x) < numPow[primeset[i]] )
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("factorial.inp", "r", stdin);
    freopen("factorial.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    sieve();

    for (int i = 1; i <= n; i ++)
        for (int j = a[i-1] + 1; j <= a[i]; j ++)
            add(j, i);

    ll lo = 0, hi = 1e14, res;
    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
