#include <bits/stdc++.h>
using namespace std;

int n, a[21];
long long ans= INT_MAX, S=0;
map<long long, long long> d;

void xuat(){
    long long s=0;
    for (int i=1; i<=n; i++)
        if ( d[a[i]] == 1 )
            s+=a[i];
    ans=min(ans,abs(S-2*s));
}

void gen(int i){
    for (int j=0; j<=1; j++){
        d[a[i]]=j;
        if (i==n) xuat();
        else gen(i+1);
    }
}

int main(){
    freopen("DiviApples.inp","r",stdin);
    freopen("DiviApples.out","w",stdout);
    cin >> n ;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        S+=a[i];
    }
    gen(1);
    cout << ans;
    return 0;
}
