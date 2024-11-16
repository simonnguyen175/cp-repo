#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int oo = 2e9;

int n;
int a[N],mi[N],h[N],ma[N],ans=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    mi[0]=1e9;
    for(int i=1;i<=n;i++)
        mi[i]=min(mi[i-1],a[i]);
    h[1]=0;
    for(int i=2;i<=n;i++){
        h[i]=max(h[i-1],a[i]-mi[i-1]);
    }
    ma[n+1]=0;
    for(int i=n;i>=1;i--)
        ma[i]=max(ma[i+1],a[i]);
    for(int i=3;i<n;i++)
        ans=max(ans,ma[i+1]-a[i]+h[i-1]);
    cout<<ans;
    return 0;
}
