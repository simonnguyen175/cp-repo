#include <bits/stdc++.h>
using namespace std;
string s;
int i,n;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>s; n=s.size();
    s=' '+s;
    i=1;
    while(s[i]==s[n-i+1])
    {
        if (i==n/2) break;
        i++;
    }
    for (i=1;i<=n;i++)
    {
        s=s+'1';
    }
    cout<<i;
    if (i==n/2) cout<<"YES"; else cout<<"NO";
}
