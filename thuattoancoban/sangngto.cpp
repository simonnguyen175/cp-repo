#include <bits/stdc++.h>
#define nmax 10000007
using namespace std;
bool isPrime[nmax];
void sieve()
{
 memset(isPrime,true,sizeof(isPrime));
 isPrime[1] = false;
 for(long long i = 2; i * i <= nmax; ++i)
 if(isPrime[i])
 for(long long j = i * i; j <= nmax; j += i)
 isPrime[j] = false;
}
int main()
{
 sieve();
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 if(isPrime[i]) cout<<i<<'\n';
}
