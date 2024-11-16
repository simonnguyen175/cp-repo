#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, s[100001],a[100001], ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(ll i=1; i<=n; i++)
        cin>>a[i];
    for(ll i=1; i<=n; i++){
        s[i]=max(s[i-1]+a[i], a[i]);
        ans=max(ans,s[i]);
    }
    cout<<ans;
}
