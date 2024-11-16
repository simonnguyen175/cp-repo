#include <bits/stdc++.h>
using namespace std;

int n, q;
long long a[100001], l[100001], r[100001];
long long f[100001];

int main(){
    //INPUT&&SETUP
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++)
        cin >> l[i] >> r[i];
    //SOLVE
    f[1]=max(a[1],(long long)0);
    for (int i=2; i<=n; i++)
        f[i] = max(f[i-1], max(f[i-1]+a[i], (long long)0) );
    for (int i=1; i<=q; i++)
        cout << f[r[i]] - f[l[i]-1] <<"\n";
    return 0;
}
