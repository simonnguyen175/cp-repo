#include <bits/stdc++.h>
using namespace std;
long long a[100001],n,k,i;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>k;
    for (i=1; i<=n; i++) cin>>a[i];
    sort (a+1, a+1+n);
    cout <<a[k]<<"\n";
    cout<<a[n-k+1];
}
