#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, p;

int main(){
    if ( fopen("sale.inp", "r") ){
        freopen("sale.inp", "r", stdin);
        freopen("sale.out", "w", stdout);
    }
    cin >> n >> k >> p;
    cout << ( n - n / (k + 1) ) * p;
    return 0;
}
