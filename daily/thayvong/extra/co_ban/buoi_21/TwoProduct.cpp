#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll k, ans;

int main(){
    freopen("TwoProduct.inp","r",stdin);
    freopen("TwoProduct.out","w",stdout);
    cin >> k;
    for (int i=1; i<=sqrt(k); i++){
        ll x=k/i;
        ans += 1+2*(x-i);
    }
    cout << ans;
    return 0;
}
