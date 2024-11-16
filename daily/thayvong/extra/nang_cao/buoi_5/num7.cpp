#include <bits/stdc++.h>
using namespace std;

long long k,x,a[1000001];

int main(){
    freopen("NUM7.inp","r",stdin);
    freopen("NUM7.out","w",stdout);
    cin >> k;
    int e=7, x=7,dem=1;
    while ( e != 0 ){
        e= x % k ;
        if ( e == 0 ){
            for (int i=1; i<=dem; i++) cout <<7;
            return 0;
        }
        x=(e*10+7)%k;
        dem++;
        a[x]++;
        if (a[x] == 2 ){
            cout <<-1;
            return 0;
        }
    }
}
