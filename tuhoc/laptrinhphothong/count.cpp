#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 123456789

ll n;

ll modun(ll n)
{
    if ( n == 0 ) return 1;
    else
    {
        if ( n % 2 == 0 ) return ( (modun(n/2) % MOD )*( modun(n/2) % MOD) ) % MOD;
        else
            return ( (modun(n/2) % MOD ) * ((( modun(n/2) % MOD)*(2 % MOD))%MOD) ) % MOD;
    }
}

int main(){
    cin >> n;
    cout << modun(n-1);
    return 0;
}
