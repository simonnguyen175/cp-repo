#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

long long n, s, k;
bool prime[N];

void sieve(){
    memset(prime, 1, sizeof prime);
    prime[1] = 0;
    for (int i = 1; i*i <= 1000000; i ++) if ( prime[i] )
    for (int j = i*i; j <= 1000000; j += i) prime[j] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> k >> n;
    sieve();
    for (int i = 1; i <= 1000000; i ++) if ( prime[i] && n % i == 0 ){
        cout << i << ' ';
    }

    return 0;
}
