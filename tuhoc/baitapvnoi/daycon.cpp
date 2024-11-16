#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll mini=1e5,n,a[100005],s[100005],ans=-1,d,c,g,k;

bool check(ll x,ll s[],ll n,ll k)
{
    for(int i=x;i<=n;i++){
        if((s[i]-s[i-x])>k)
            return false;
    }
    return true;
}

int main()
{
    cin>>n>>k;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    d=1;
    c=n;
    while(d<=c){
        g=(d+c)/2;
        if(check(g,s,n,k)==true){
            ans=max(ans,g);
            d=g+1;
        }
        else
            c=g-1;
    }
    cout<<ans;
}
