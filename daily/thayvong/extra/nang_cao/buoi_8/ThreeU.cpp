#include <bits/stdc++.h>
using namespace std;

long long n;
long long a[200001];
bool isPrime[1000001];

void sieve(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = false;
    for(long long i = 2; i * i <= 1000001; ++i)
        if(isPrime[i])
            for(long long j = i * i; j <= 1000001; j += i)
                isPrime[j] = false;
}

bool cp(long long n){
    if ( sqrt(n) == (float)sqrt(n) )
        return true;
    return false;
}

int main(){
    freopen("ThreeU.inp","r",stdin);
    freopen("ThreeU.out","w",stdout);
    cin >> n;
    sieve();
    long long dem=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        if (cp(a[i]))
            if ( isPrime[( long long )sqrt(a[i])] )
                dem++;
    }
    cout << dem;
    return 0;
}
