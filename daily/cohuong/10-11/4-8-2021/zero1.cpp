#include <bits/stdc++.h>
#define simon "zero"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=2e6+1;
const oo=1e18;

int q, n;
bool isPrime[N];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1]=0;
    for (int i=2; i*i<=N; i++)
        if ( isPrime[i] )
            for (int j=i*i; j<=N; j+=i)
                isPrime[j]=0;
}


int solve(int n){
    int res=0;
    while ( n != 0 ){
        if ( isPrime[n] ){
            n--;
            res++;
            continue;
        }
        for (int i=sqrt(n); i>=2; i--)
            if ( n % i == 0 ){
                res++;
                n=n/i;
                continue;
            }
    }
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    sieve();
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> n;
        cout << solve(n) <<'\n';
    }
}
