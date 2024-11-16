#include <bits/stdc++.h>
using namespace std;
string s; long long t,i;
int main()
{
    cin>>s; t=0;
    for (i=0;i<s.size();++i)
    t=t+s[i]-48;
    cout<<t;
}
