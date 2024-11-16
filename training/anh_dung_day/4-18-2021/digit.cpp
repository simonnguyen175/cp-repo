#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, k;

ll multimod(ll x, ll n, ll m) {
    if ( n == 0 ) return 0;
    else{
        ll tmp=multimod(x, n/2, m);
        if ( n % 2 == 1 ) return (((tmp%m)+(tmp%m))%m+(x%m))%m;
        else return ((tmp%m)+(tmp%m))%m;
    }
}


ll powmod(ll x, ll n, ll m){
    if ( n == 0 ) return 1;
    else{
        ll tmp=powmod(x, n/2, m);
        if ( n % 2 == 1 ) return multimod((multimod(tmp, tmp, m)), x, m);
        else return multimod(tmp, tmp, m);
    }
}

int kth_digit_fact(ll a, ll b, ll k){
    cout << multimod(a, powmod(10, k-1, b), b) << '\n';
    return 10*( multimod(a, powmod(10, k-1, b), b) ) / b;
}

int main(){
    cin >> a >> b >> k;
    cout << kth_digit_fact(a, b, k);
    return 0;
}
