#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
const long long oo=1e18;

int n, x[N];
long long s[N], ans=oo;

long long chiphi(int d, int c){
    int pos = (d+c)/2;
    return (pos-d)*x[pos]-(s[pos-1]-s[d-1])+s[c]-s[pos]-(c-pos)*x[pos];
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    freopen("TwoC.inp", "r", stdin);
    freopen("TwoC.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i];
    for (int i=1; i<=n; i++)
        s[i] = s[i-1] + x[i];
    for (int i=1; i<=n; i++)
        ans = min( ans, chiphi(1, i)+chiphi(i+1, n) );
    cout << ans;
    return 0;
}
