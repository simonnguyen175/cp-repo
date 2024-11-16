#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "MaxPK"
using namespace std;

ll a, b, x, k=1;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> a >> b >> x;
    if ( a > b ){cout << "No solution"; return 0;}
    if ( x > b ) cout << "No solution";
    else{
        ll tmp=x;
        while ( x <= b ){
            x*=tmp;
            k++;
        }
        k--; x/=tmp;
        if  ( x < a ) cout << "No solution";
        else cout << k;
    }
    return 0;
}
