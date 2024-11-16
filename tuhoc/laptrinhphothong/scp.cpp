#include <bits/stdc++.h>
using namespace std;
long long n,a[101],s;
bool    scp(long long x)
{
    if (x==(int)sqrt(x)*(int)sqrt(x)) return true;
    else return false;
}
int main()
{
    cin>>n;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        if (scp(a[i])==true) s++;
    }
    cout<<s;
}
