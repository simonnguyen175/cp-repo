#include <bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
    cin>>s;
    for (long long i=0; i<=s.size(); i++)
        if (s[i]>='a' && s[i]<='z')
            t+=s[i];
    cout<<t;
}
