#include <bits/stdc++.h>
using namespace std;
string s;
char ch;
long long i,dem,n;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>s>>ch; dem=0;
    n=s.length();
    for (i=0;i<=n;i++)
        {if(s[i]==ch) dem++;}
    cout<<dem;
}

