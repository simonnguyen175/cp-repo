#include <bits/stdc++.h>
using namespace std;
int n,A[1000002],l,d,kt[100002];
long long k,F[52][52];
int P[1000002];
vector <int> nto;
unordered_map <int,int> mp;
void sub2()
{
    int i;
    int m=0;
    memset(P,0,sizeof(P));
    for (i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }
    sort(A+1,A+n+1);
    for (i=1;i<=n;i++)
    {
        if (A[i]%2==0&&mp[A[i]/2]>0)
        {
            mp[A[i]]=mp[A[i]/2];
            P[mp[A[i]]]++;
        }
        else {m++;P[m]++;mp[A[i]]=m;}
    }
    long long res=0;
    long long t=1;
    for (i=1;i<=m;i++)
    {
        int p=P[i];
        res+=(p+1)/2;
        if (p%2==0) t*=(p/2+1);
        t%=k;
    }
    cout<<res<<' '<<t;
}
long long pow(int n,int p)
{
    if (p==0) return 1;
    long long t=pow(n,p/2);
    t=t*t;t%=k;
    if (p%2==0) return t;
    else return (t*n)%k;
}
void sub3()
{
    long long t=1;
    long long dd=1;
    int l=0;int r=n;
    int res=0;
    for (int h=1;h<=32;h++)
    {
        int d=0;int c=n;
        t*=2;d=0;c=n;
        while (d<=c)
        {
            int x=(d+c)/2;
            if (t*x<=n) d=x+1;
            else
            { l=x;c=x-1;}
        }
        if (l%2==0) l++;
        if (r%2==0) r--;
        if (l>r) break;
        int m=((r-l)/2+1);
        res+=m*((h+1)/2);
       // cout<<h<<' '<<l<<' '<<r<<' '<<m<<' '<<res<<endl;
        if (h%2==0) dd*=pow((h/2)+1,m);
        dd%=k;
        r=l-1;
    }
    cout<<res<<' '<<dd;
}
int main()
{
    freopen("d2set.inp","r",stdin);
    freopen("d2set.out","w",stdout);
    cin>>n>>k;
    if (n>1e6)
        sub3();
    else sub2();
}
