#include <bits/stdc++.h>
using namespace std;
string st;
long long e,h,dem[2020],ans=0,n;
int main()
{
    freopen("Divisor2019.inp","r",stdin);
    freopen("Divisor2019.out","w",stdout);
    cin>>st;
    n=st.size(); e=0; int k=1; dem[0]=1;
    for (long long i=n-1; i>=0; i--)
    {
        e=(st[i]-48)*k+e;
        e%= 2019;
        ans+=dem[e];
        dem[e]++;
        k=(k*10) % 2019;
    }
    cout << ans;
}
