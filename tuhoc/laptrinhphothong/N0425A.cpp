#include <bits/stdc++.h>
using namespace std;
long long n,a[1000],i,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; dem=0;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=1; i<=n; i++)
    {
        if (a[i]%7==0)
        {
            cout<<"YES";
            break;
        }
        else dem++;
    }
    if (dem==n) cout<<"NO";
}
