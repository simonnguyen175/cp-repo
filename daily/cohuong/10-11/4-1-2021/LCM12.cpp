#include <bits/stdc++.h>
using namespace std;
bool nt[1000005];
int a[1000005];
int n,m;
void sangnt()
{
    for (int i=0;i<=1000000;i++) nt[i]=true;
    nt[0]=nt[1]=false;
    for (int i=2;i<=1000;i++){
        if (nt[i]==false) continue;
        int j=i*i;
        while (j<=1000000){
            nt[j]=false;
            j+=i;
        }
    }
    m=0;
    for (int i=1;i<=1000000;i++){
        if (nt[i]==true){
            m++;
            a[m]=i;
        }
    }
}
void solve()
{
    int dem=0;
    int p=n;
    while (p>=5){
        p=p/5;
        dem++;
    }
    int i=1;
    int res=1;
    while (a[i]<=n && i<=m){
           // cout<<a[i]<<' ';
        if (a[i]==5) {
            i++;
            continue;
        }
        if (a[i]==2){
            int t=0;
            p=n;
            while (p>=2){
                p=p/2;
                t++;
            }
            for (int j=1;j<=t-dem;j++){
                res=res*2;
                res%=10;
            }
        }
        else {
            p=n;
            while (p>=a[i]){
                p=p/a[i];
                res=res*a[i];
                res%=10;
            }
        }
        i++;
        //cout<<res<<' ';

    }
    cout<<res<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LCM12.inp","r",stdin);
    freopen("LCM12.out","w",stdout);
    sangnt();
    while (cin>>n){
        if (n!=0) solve();
    }
}
