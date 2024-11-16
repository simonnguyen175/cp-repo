#include <bits/stdc++.h>
using namespace std ;
int n,a[100001],ln;
int main()
{
    cin>>n;
    ln=-1000000000;
    for (int i=1; i<=n;i++)
    {
        cin>>a[i];
        ln=max(ln,a[i]);
    }
    cout<<ln;
}
