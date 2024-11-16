#include <bits/stdc++.h>
using namespace std;

long long a,b,c,d;

long long soboi(long long x){
    return b/x-(a-1)/x;
}

int main(){
    freopen("AntiDivision.inp","r",stdin);
    freopen("AntiDivision.out","w",stdout);
    cin >> a >> b >> c >> d;
    long long x=c*d/__gcd(c,d);
    long long ans = b-a+1;
    ans -= soboi(c)+soboi(d)-soboi(x);
    cout << ans;
    return 0;
}
