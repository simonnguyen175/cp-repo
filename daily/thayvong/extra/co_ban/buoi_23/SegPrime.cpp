#include <bits/stdc++.h>
using namespace std;
const int N=1e7+20;

int n;
bool isPrime[N];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[1] = false;
    for(int i = 2; i*i<=N; ++i)
        if(isPrime[i])
            for(int j=i*i; j<=N; j+=i)
                isPrime[j] = false;
}


int main(){
    freopen("SegPrime.inp","r",stdin);
    freopen("SegPrime.out","w",stdout);
    sieve();
    cin >> n;
    for (int i=n; i>=1; i--)
        if ( isPrime[i] ) {cout << i <<' '; break;}
    int i=n;
    while (!isPrime[i]) i++;
    cout << i;
    return 0;
}
