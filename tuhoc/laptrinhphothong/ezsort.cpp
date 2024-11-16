#include <bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],i,n;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; long long dem;
    for (i=1; i<=n; i++){ cin >> a[i]; b[i]=a[i];}
    sort (a+1,a+1+n);
    for (i=1; i<=n; i++)
        if (b[i] != a[i]) dem++;
    cout<<dem;
}
