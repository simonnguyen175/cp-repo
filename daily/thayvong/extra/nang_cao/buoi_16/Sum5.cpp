#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

long long s;
int n, a[N], d[6], ans;

int main(){
    freopen("Sum5.inp","r",stdin);
    freopen("Sum5.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    d[0]=1;
    for (int i=1; i<=n; i++){
        s+=a[i];
        int x=s%5;
        ans+=d[x];
        d[x]++;
    }
    cout << ans;
    return 0;
}
