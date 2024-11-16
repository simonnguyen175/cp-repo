#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>s;
    s=' '+s;
    for (int i=1;i<=s.size();i++)
        s[i]=toupper(s[i]);
    cout<<s;
}
