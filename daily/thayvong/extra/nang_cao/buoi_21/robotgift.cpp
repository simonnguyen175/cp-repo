#include <bits/stdc++.h>
#define simon "robotgift"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N = 1e6;
const int T = 1e5+5;
const ll oo=1e15;
const int MOD=123456789;

int t, n, a[N+2], d[N+2];
vector<int> b[N+2];
bool isPrime[N+2];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[1]=false;
    for (int i=2; i<=N; i++)
        if ( isPrime[i] == true ){
            b[i].push_back(i);
            for (int j=2; i*j<=N; j++){
                isPrime[i*j]=false;
                b[i*j].push_back(i);
            }
        }
}


void solve(){
    int res=0, x, tmp=0;
    map<int, int> d;
    for (int i=1; i<=n; i++){
        if ( a[i] == 0 ) tmp++;
        else
        {
            x = a[i];
           for (auto e: b[x])
            {
             d[e]++;
             res = max(res, d[e]);
            }
        }

    }
    cout << res+tmp <<'\n';
}

int main(){
    FASTio
    if ( fopen ( simon".inp","r" ) ){
        freopen ( simon".inp", "r", stdin );
        freopen ( simon".out", "w", stdout );
    }
    sieve();
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> n;
        for (int j=1; j<=n; j++){
            cin >> a[j];
            a[j]=abs(a[j]);
        }
        solve();
    }
    return 0;
}
