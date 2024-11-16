#include <bits/stdc++.h>
using namespace std;

long long n;

int main(){
    freopen("sumgcd.inp","r",stdin);;
    freopen("sumgcd.out","w",stdout);
    cin >> n ;
    long long res=0 ;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int k=1; k<=n; k++){
                res +=__gcd(i,__gcd(j,k));
            }
    cout << res ;
}
