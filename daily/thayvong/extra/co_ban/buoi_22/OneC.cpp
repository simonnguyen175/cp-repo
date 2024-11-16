#include <bits/stdc++.h>
using namespace std;
const int N=2000001;

int n, x[N];
long long ans=0;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("OneC.inp","r",stdin);
    freopen("OneC.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i];
    for (int i=1; i<=n/2; i++)
        ans += abs(x[i]-x[n-i+1]);
    cout << ans;
    return 0;
}
