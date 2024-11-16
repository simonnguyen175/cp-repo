#include <bits/stdc++.h>
using namespace std;

int n, a[100001], gl[100001], gr[100001];

int main(){
    freopen("ChangeOneGCD.inp","r",stdin);
    freopen("ChangeOneGCD.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for ( int i=1; i<=n; i++ )
        cin >> a[i];
    gl[0]=0;
    gl[1]=a[1];
    for (int i=2; i<=n; i++)
        gl[i]=__gcd(gl[i-1],a[i]);
    gr[n]=a[n]; gr[n+1]=0;
    for (int i=n-1; i>=1; i--)
        gr[i]=__gcd(gr[i+1],a[i]);

    int ans = INT_MIN;
    for (int i=1; i<=n; i++){
        ans = max ( ans, __gcd(gl[i-1],gr[i+1]));
    }
    cout << ans;
    return 0;
}
