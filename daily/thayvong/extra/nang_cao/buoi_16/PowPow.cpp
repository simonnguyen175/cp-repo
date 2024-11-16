#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;

ll n, a, b, c, ans[100001];

ll mu(ll a, ll n, ll p){
    if ( n == 0 ) return 1;
    else{
        ll tmp=mu(a,n/2,p);
        if ( n % 2 == 1 ) return ((((tmp%p)*(tmp%p))%p)*(a%p))%p;
        else return ((tmp%p)*(tmp%p))%p;
    }
}

int main(){
    //freopen("PowPow.inp","r",stdin);
    //freopen("PowPow.out","w",stdout);
    cin >> n;
    int nans=0;
    for (ll i=1; i<=n; i++){
        cin >> a >> b >> c;
        ll bc=mu(b, c, MOD-1);
        ll tmp=mu(a, bc, MOD);
        ans[++nans]=tmp;
    }
    for (ll i=1; i<=nans; i++)
        cout << ans[i] <<'\n';
    return 0;
}
