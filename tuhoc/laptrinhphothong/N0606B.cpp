#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll sum(string s)
{
    ll d=0;
    for(ll i=0; i<s.length();++i)
        d=d+s[i]-48;
    return d;
}
int main()
{
    cin>>a;
    cout<<sum(a);
}
