#include <bits/stdc++.h>
using namespace std;

bool nto(int n){
    if ( n <= 1 ) return false;
    else
        for (int i=2; i<=sqrt(n); i++)
            if ( n % i == 0 ) return false;
    return true;
}

int x,a[10],b[10000000];

int main(){
    freopen("SwapPrime.inp","r",stdin);
    freopen("SwapPrime.out","w",stdout);
    cin >> x;
    int n=0, m=0;
    while ( x > 0 ){
        a[++n]=x%10;
        x/=10;
    }
    sort(a+1,a+1+n);
    do{
        int y=0;
        for (int i=1; i<=n; i++)
            y=y*10+a[i];
        b[++m]=y;
    }while (next_permutation(a+1,a+1+n));
    int c=0;
    sort(b+1,b+1+m);
    for (int i=1; i<=m; i++)
        if ( nto(b[i]) ){
            c=1;
            cout << b[i] <<"\n";
        }
    if ( c == 0 ) cout <<"Hello2021";
    return 0;
}
