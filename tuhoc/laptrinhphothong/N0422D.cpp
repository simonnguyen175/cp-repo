#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i,temp,b,e,ln;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    i=1;ln=0;temp=0;
    while  (i<=n)
    {
        cin>>a[i];
        if (a[i]%2==0) temp++;
        else
        {
            if (temp>ln)
            {
                    b=i-temp;
                    e=i-1;
                    ln=temp;
            }
            temp=0;
        }
        i++;
    }
    cout<<ln<<"\n";
    for (i=b; i<=e; i++) cout<<a[i]<<" ";
}
