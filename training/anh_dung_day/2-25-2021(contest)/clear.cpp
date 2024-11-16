#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, t, a[5001], ans=5000;
bool b[21];

void xuli(){
    int tmp=0, dem=0;
    for (int j=1; j<=n-1; j++){
        if ( b[j] ){
            tmp+=a[j];
            dem++;
        }
        else tmp-=t;
        if ( tmp < 0 ) return;
    }
    if ( tmp + a[n] >= 0 ) ans=min(ans, dem);
}

void gen(int i){
    for (int j=0; j<=1; j++){
        b[i]=j;
        if ( i == n-1 ) xuli();
        else gen(i+1);
    }
}

void sub1(){
    if ( n == 1 ){
        if ( a[1] > 0 ) cout << 1;
        else cout << -1;
    }
    else{
        gen(1);
        if ( ans == 5000 ) cout << -1;
        else cout << ans+1;
    }
}

int main(){
    freopen("clear.inp","r",stdin);
    freopen("clear.out","w",stdout);
    cin >> n >> t;
    for (int i=1; i<=n; i++) cin >> a[i];
    if ( n <= 20 ){sub1(); return 0;}
}
