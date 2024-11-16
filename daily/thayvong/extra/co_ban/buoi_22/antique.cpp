#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n, x[N], a[N], s=0;
long long ans=0;

int main(){
    freopen("antique.inp","r",stdin);
    freopen("antique.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> x[i];
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s+=a[i];
    }
    int tmp=0, pos;
    for (int i=1; i<=n; i++)
        if ( tmp > (s+1)/2 ) break;
        else{
            pos=i;
            tmp+=a[i];
        }
    for (int i=1; i<=n; i++)
        ans += a[i]*abs( x[pos] - x[i] );
    cout << ans;
    return 0;
}
