#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "Ucdayso"
using namespace std;
const int N = 1e5 + 5;

int n;
long long a[N];

long long tu(int x){
    long long res = 0;
    for (int i = 1; i <= sqrt(x); i ++)
        if ( x % i == 0 )
            if ( i * i != x ) res += i + (x/i);
                else res += i;
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    long long d = a[1];
    for (int i = 2; i <= n; i ++)
        d = __gcd(d, a[i]);

    cout << tu(d);
    return 0;
}
