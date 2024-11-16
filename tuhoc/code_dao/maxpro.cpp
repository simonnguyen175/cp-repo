#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a, b, c, M;
int main(){
    cin >> a >> b >> c; cin >> M;
    ll p1=((a%M)*(b%M))%M;
    ll p2=((b%M)*(c%M))%M;
    ll p3=((c%M)*(a%M))%M;
    cout << max (p1, max(p2, p3));
    return 0;
}
