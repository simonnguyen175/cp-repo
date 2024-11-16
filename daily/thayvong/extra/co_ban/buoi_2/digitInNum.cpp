#include <bits/stdc++.h>
using namespace std;
long long n[1000],k[1000],t,i,cs,c;
int main()
{
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n[i];
        cin>>k[i];
    }
    for (i=1;i<=t;i++)
    {
        if (n[i]==0)
        {
                if (k[i]==n[i]) {cout<<"Yes"<<"\n"; continue;}
                else {cout<<"No"<<"\n";continue;}
        }
        c=0;
        while (n[i] != 0)
        {
            cs=n[i] % 10;
            if (cs==k[i]) {cout <<"Yes"<<"\n"; c=1; break;}
            n[i]=n[i]/10;
        }
        if (c!=1) cout<<"No"<<"\n";
    }
}
