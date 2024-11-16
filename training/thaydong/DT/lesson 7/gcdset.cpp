#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, ans = 0;
ll a[N];
int lpf[1000005];
vector<int> primeset;

void sieve(){
    memset(lpf, 0, sizeof lpf);
    for (int i = 2; i * i <= 1000000; i ++)
        if ( !lpf[i] )
        for (int j = i * i; j <= 1000000; j += i)
            lpf[j] = i;
    for (int i = 2; i <= 1000000; i ++)
        if ( !lpf[i] ) lpf[i] = i, primeset.pb(i);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int x : primeset){
        int tmp = 0;
        for (int i = 1; i <= n; i ++)
            if ( a[i] % x == 0 ){
                while ( a[i] % x == 0 )
                    a[i] /= x;
                tmp ++;
            }
        ans = max(ans, tmp);
    }

    vector<ll> d;
    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++)
        d.pb(__gcd(a[i], a[j]));

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for (int x : d){
        if ( x == 1 ) continue;
        int tmp = 0;
        for (int i = 1; i <= n; i ++)
            if ( a[i] % x == 0 ) tmp ++;
        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}
