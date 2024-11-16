#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
typedef pair <int,int> pp;
int m,n,k;
pp A[100002];
pair <int,long long> bit[100002];
int dL[100002],dR[100002];
long long L[100002],R[100002];
void updateL(int i,int val,long long num)
{
    for (i;i<=k;i+=i&(-i))
    {
        if (bit[i].first<val)
        {
            bit[i].first=val;
            bit[i].second=0;
        }
        if (bit[i].first==val)
        {
            bit[i].second+=num;
            bit[i].second%=mod;
        }
    }
}
pair <int,long long> getL(int i)
{
    pair <int,long long> ans;ans.first=0;ans.second=0;
    for (i;i>=1;i-=i&(-i))
    {
        if (ans.first<bit[i].first)
        {
            ans.first=bit[i].first;
            ans.second=0;
        }
        if (ans.first==bit[i].first)
        {
            ans.second+=bit[i].second;
            ans.second%=mod;
        }
    }
    return ans;
}
void updateR(int i,int val,long long num)
{
    for (i;i>=1;i-=i&(-i))
    {
        if (bit[i].first<val)
        {
            bit[i].first=val;
            bit[i].second=0;
        }
        if (bit[i].first==val)
        {
            bit[i].second+=num;
            bit[i].second%=mod;
        }

    }
}
pair <int,long long> getR(int i)
{
     pair <int,long long> ans;ans.first=0;ans.second=0;
    for (i;i<=k;i+=i&(-i))
    {
        if (ans.first<bit[i].first)
        {
            ans.first=bit[i].first;
            ans.second=0;
        }
        if (ans.first==bit[i].first)
        {
            ans.second+=bit[i].second;
            ans.second%=mod;
        }
    }
    return ans;
}
void compress()
{
    vector <int> P1,P2;
    map <int,int> mp1,mp2;
    for (int i=1;i<=k;i++)
    {
        P1.push_back(A[i].first);
        P2.push_back(A[i].second);
    }
    sort(P1.begin(),P1.end());
    sort(P2.begin(),P2.end());
    mp1[P1[0]]=1;mp2[P2[0]]=1;int dem1=1;int dem2=1;
    for (int i=1;i<k;i++)
    {
        if (P1[i]>P1[i-1]) mp1[P1[i]]=++dem1;
        if (P2[i]>P2[i-1]) mp2[P2[i]]=++dem2;
    }
    for (int i=1;i<=k;i++)
    {
        A[i].first=mp1[A[i].first];
        A[i].second=mp2[A[i].second];
    }
}
void calL()
{
    memset(bit,0,sizeof(bit));
    updateL(1,0,1);
    for (int i=1;i<=k;i++)
    {
        int val=getL(A[i].second).first;
        long long t=getL(A[i].second).second;
        updateL(A[i].second,val+1,t);
        dL[i]=val+1;
        L[i]=t;
    }
    long long s=getL(k).second;
    int d=getL(k).first;
    //cout<<d<<' '<<s<<endl;
}
void calR()
{
    memset(bit,0,sizeof(bit));
    updateR(k,0,1);
    for (int i=k;i>=1;i--)
    {
        int val=getR(A[i].second).first;
        long long t=getR(A[i].second).second;
        updateR(A[i].second,val+1,t);
        dR[i]=val+1;
        R[i]=t;
    }
}
void solve()
{
    cin>>m>>n>>k;
    for (int i=1;i<=k;i++)
        cin>>A[i].first>>A[i].second;
    sort(A+1,A+k+1);
    compress();
    calL();
    long long s=getL(k).second;
    int d=getL(k).first;
    calR();

    int res=0;
    for (int i=1;i<=k;i++)
    {
        long long t=L[i]*R[i];t%=mod;
        if (dL[i]+dR[i]-1==d&&t==s) res++;
    }
    cout<<res;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("ggame.inp","r",stdin);
    freopen("ggame.out","w",stdout);
    solve();
}

