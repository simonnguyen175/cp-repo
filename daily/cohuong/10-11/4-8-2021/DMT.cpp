#include <bits/stdc++.h>
#define simon "DMT"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e6+1;
const ll oo=1e18;

ll t, a, b, f[N];
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
        if ( isPrime[i] && i != 3 ) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    for (int i=27; i<=N; i++)
        f[i]++;
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> a >> b;
        int k=(int)sqrt(b/9),t=(int)sqrt(a/9);
		if(t<sqrt(a*1.0/9)) t++;
		if(k>sqrt(b*1.0/9)) k--;
        cout << f[k]-f[t-1] <<'\n';
    }
    return 0;
}
