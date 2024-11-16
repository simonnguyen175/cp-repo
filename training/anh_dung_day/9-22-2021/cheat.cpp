#include<bits/stdc++.h>
using namespace std;
const int N=405;
int t,n,m,cnt;
bitset<N> a[N];
bool check[N],ds[N];
void solve(){
    cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) a[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char x;
            cin>>x;
            if(x=='Y') a[i][j]=1; else a[i][j]=0;
        }
    for(int i=2;i<=n;i++)
        if((a[i] & a[1])==a[1]) cnt++;
    if(cnt!=0) {
        if(cnt==1) cout<<'Y'<<endl;
        else cout<<'N'<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
    {
        cnt=0;
        for(int j=1;j<=m;j++)
        {

            ds[j]=check[j]=false;
            if(a[1][j]&&a[i][j]) {ds[j]=check[j]=true;cnt++;}
        }
        for(int id=2;id<=n;id++)
        {
            int dem=0;
            if(id==i) continue;
            for(int j=1;j<=m;j++)
                if(a[id][j]&&check[j]) dem++;
            if(dem==cnt)
                for(int j=1;j<=m;j++)
                if(a[id][j]&&a[i][j]) ds[j]=true;
        }
        for(int j=1;j<=m;j++)
            if(a[i][j]&&!ds[j]) {cout<<'Y'<<endl;return;}
    }
    cout<<'N'<<endl;


}
int main()
{
    cin>>t;
    while(t--)
        solve();

}
