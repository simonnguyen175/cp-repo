#include <bits/stdc++.h>
using namespace std;
map <long long, long long> mp;
long long n,x,a[500001];
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>x;
    for (int i=1; i<=n; i++) cin>>a[i];
    s=0;
    mp[a[1]]=1;
    for (long long i=2; i<=n; i++)
    {
        s += mp[x-a[i]];
        mp[a[i]]++;
    }
    cout << s ;
}
