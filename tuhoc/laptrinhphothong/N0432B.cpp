#include <bits/stdc++.h>
using namespace std;
long long n,i,e,o,a[100000],odd[100000],even[100000];
int main()
{
    ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    cin>>n; o=1; e=1;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]%2==0) {even[e]=a[i];e++;}
        if (a[i]%2!=0) {odd[o]=a[i];o++;}
    }
    for (i=1;i<=e-1;i++) cout <<even[i]<<" ";
    for (i=1;i<=o-1;i++) cout <<odd[i]<<" " ;
}

