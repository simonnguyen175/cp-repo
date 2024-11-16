#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s; ll d;
int main ()
{
    getline(cin,s);
    if (s[0]!=' ') d=1;
    for (ll i=0;i<s.length()-1;++i)
        if (s[i]==' ' and s[i+1]!=' ') d++;
    cout<<d;
}
