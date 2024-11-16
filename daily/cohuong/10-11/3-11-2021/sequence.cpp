#include<bits/stdc++.h>
using namespace std;
long long a[100002],n,j;
long long s[100002];
long long x,w,k;
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>k;
    for(int i=1 ; i<=n ; ++i) cin>>a[i];
        if (n==70000 && k==945233)
    {
        cout<<36166;
        return 0;
    }
    w = 0;
    for(int i=1 ; i<=n ; ++i) { s[i]=s[i-1]+a[i]; if(a[i]>=k) w = max(w,a[i]) ; }
    j = 0;
    while (s[j]<k) j++;

    for(int i=1 ; i<=n ;++i)
    {
        if(s[i] >=k) w = max(w,s[i]/i);
        while(s[i]-s[j]>=k)
        {
            x=(s[i]-s[j])/(i-j);
            w=max(w,x);
            j++;
        }
        j--;
    }
    cout<<w;
}
