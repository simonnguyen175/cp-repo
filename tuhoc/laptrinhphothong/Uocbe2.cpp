#include <bits/stdc++.h>
using namespace std;

long long n,a[500001],ans=0;
bool isPrime[10000001];

void sieve()
{
 memset(isPrime,true,sizeof(isPrime));
 isPrime[1] = false;
 for(int i = 2; i * i <= 10000001; ++i)
 if(isPrime[i])
 for(int j = i * i; j <= 10000001; j += i)
 isPrime[j] = false;
}

long long UocMinSec(long long n){
    for (int i=2; i<=sqrt(n); i++)
        if ( n % i == 0 )
            return i;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("Uocbe2.inp","r",stdin);
    freopen("Uocbe2.out","w",stout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sieve();

    for (int i=1; i<=n; i++){
        if ( isPrime[a[i]] )
            ans+=a[i];
        else
            ans+=UocMinSec(a[i]);
    }
    cout << ans;
    return 0;
}
