#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long mod=1e9+7;

int n, a, b;
long long s[1000001];

long long mu(int x, int y){
    if ( y == 1 ) return x%mod;
    long long p = mu(x,y/2);
    p = (p*p)%mod;
    if ( y%2 == 1 )
        p = (p*x)% mod;
    return p;
}

int main(){
    freopen("QueryPower.inp","r",stdin);
    freopen("QueryPower.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=1000000; i++){
        s[i]=s[i-1]+mu(i,2021);
        s[i]%=mod;
    }
    for (int i=1; i<=n; i++){
        cin >> a >> b;
        if ( a == 0 ) cout << s[b] <<'\n';
        else cout << (s[b]-s[a-1]+mod)%mod <<'\n';
    }
    return 0;
}
