#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];
long long s;

int main(){
    freopen("reformSum.inp","r",stdin);
    freopen("reformSum.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s+=a[i];
    }
    sort(a+1, a+1+n);
    if ( a[1] < 0 ) cout << s-a[1];
    else cout << s;
    return 0;
}
