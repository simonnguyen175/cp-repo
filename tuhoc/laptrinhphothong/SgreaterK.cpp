#include <bits/stdc++.h>
using namespace std;

long long n, k, i, a[500001], s, x;

int main(){
    freopen("SgreaterK.inp","r",stdin);
    freopen("SgreaterK.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k ;
    for (long long i=1; i<=n; i++)
        cin >> a[i];
    s=0; x=0; i=1;
    for (long  long j=1; j<=n; j++){
        x = x + a[j];
        if ( x >= k ){
            while ( i< j && x-a[i]>=k){
                x-=a[i];
                i++;
            }
        s+=i;
        }
    }
    cout << s ;
}
