#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, n;

ll mu(ll a, ll n){
    if ( n == 1 ) return a;
    else{
        ll tmp=mu(a,n/2);
        if ( n % 2 == 1 ) return tmp*tmp*a;
        else return tmp*tmp;
    }
}

int main(){
    cin >> a >> n;
    cout << mu(a,n);
    return 0;
}
