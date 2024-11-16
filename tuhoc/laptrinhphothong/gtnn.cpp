#include <bits/stdc++.h>
using namespace std ;
int n,a[100],nn;
int main()
{
    cin>>n;
    nn=1000000000;
    for (int i=1; i<=n;i++)
    {
        cin>>a[i];
        nn=min(nn,a[i]);
    }
    cout<<nn;
}
