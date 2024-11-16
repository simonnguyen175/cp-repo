#include <bits/stdc++.h>
using namespace std;

long long n, a[10000001], f[10000001];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cin.tie(0);

    freopen("selseq.inp","r",stdin);
    freopen("selseq.out","w",stdout);
    cin >> n ;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    f[1]=a[1];
    f[2]=max(a[1],a[2]);
    for (int i=3; i<=n; i++){
        long long x=a[i];
        long long y=f[i-1];
        long long z=f[i-2]+a[i];
        f[i] = max(x,max(y,z));
    }
    cout << f[n];
    return 0;
}
