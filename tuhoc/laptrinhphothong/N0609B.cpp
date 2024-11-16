#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll dem[999],d=0;
int main ()
{
 cin>>s;
 for (ll i=0;i<s.length();++i)
 {
 dem[s[i]]++;
 }
 for (char j='a';j<='z';++j)
 {
 if (dem[j]>0) d++;
 }
 cout<<d;
}
