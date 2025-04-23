#include <bits/stdc++.h>
#define ll long long
#define nmax 100005

using namespace std;

ll n,m,a[nmax],b[nmax],ans=-1;
bool thi[nmax],d[nmax];

bool check(ll k)
{
    memset(thi,false,nmax);
    memset(d,false,nmax);
    for(int i=k;i>=1;i--){
        if(!d[a[i]]){
            thi[i]=true;
            d[a[i]]=true;
        }
    }
    ll on=0,th=0;
    for(int i=1;i<=k;i++){
        if(thi[i]){
            if(on>=b[a[i]]){
                on-=b[a[i]];
                th++;
            }
            else
                break;
        }
        else
            on++;
    }
    if(th==m)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    ll dau=1,cuoi=n;
    while(dau<=cuoi){
        ll giua=(dau+cuoi)/2;
        if(check(giua)){
            ans=giua;
            cuoi=giua-1;
        }
        else
            dau=giua+1;
    }
    cout<<ans;
}

