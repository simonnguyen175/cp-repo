#include <bits/stdc++.h>
using namespace std;
long long n,a[101],s;
int main()
{
    cin>>n;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]>=500 && a[i]<=3000)
            s++;
    }
    cout<<s;
}
