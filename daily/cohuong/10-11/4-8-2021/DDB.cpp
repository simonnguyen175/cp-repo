#include <bits/stdc++.h>
#define simon "DDB"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=2e6+1;
const ll oo=1e18;

int q, n, f[N];
bool isPrime[N];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1]=0;
    for (int i=2; i*i<=N; i++)
        if ( isPrime[i] )
            for (int j=i*i; j<=N; j+=i)
                isPrime[j]=0;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    sieve();
    for (int i=1; i<=N; i++)
        if ( isPrime[i] ) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> n;
        cout << f[2*n]-f[n] <<'\n';
    }
    return 0;
}
