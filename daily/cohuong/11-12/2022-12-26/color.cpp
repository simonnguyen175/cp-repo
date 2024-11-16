#include <bits/stdc++.h>
using namespace std;
int t;
int A[11][6],dt[11][11][11][11][11];
long long dp[11][11][11][11][11][11];
void setdt()
{
    int cs[6];
    memset(cs,0,sizeof(cs));
    while (cs[1]<=10){
        cs[2]=0;
        while (cs[2]<=10){
            cs[3]=0;
            while (cs[3]<=10){
                cs[4]=0;
                while (cs[4]<=10){
                    cs[5]=0;
                    while (cs[5]<=10)
                    {
                        int t=0;
                        for (int i=1;i<=5;i++)
                        {
                            int r=i;int l=i;
                            while (r<5&&cs[r+1]>=cs[i]) r++;
                            while (l>1&&cs[l-1]>=cs[i]) l--;
                            t=max(t,(r-l+1)*cs[i]);
                        }
                        dt[cs[1]][cs[2]][cs[3]][cs[4]][cs[5]]=t;
                        //cout<<cs[1]<<' '<<cs[2]<<' '<<cs[3]<<' '<<cs[4]<<' '<<cs[5]<<' '<<t<<endl;
                        cs[5]++;
                    }
                    cs[4]++;
                }
                cs[3]++;
            }
            cs[2]++;
        }
        cs[1]++;
    }
}
int getbit(int n,int k)
{
    return (n>>k)&1;
}
int check(int mask,int i)
{
    for (int j=1;j<=5;j++)
        if (getbit(mask,j-1)==0&&A[i][j]==1) return 0;
    return 1;
}
long long play(int s)
{
    if (s<0) return 0;
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0][0][0]=1;
    int cs[6];
    for (int i=0;i<10;i++)
        for (int i1=0;i1<=i;i1++)
        for (int i2=0;i2<=i;i2++)
        for (int i3=0;i3<=i;i3++)
        for (int i4=0;i4<=i;i4++)
        for (int i5=0;i5<=i;i5++)
            if (dt[i1][i2][i3][i4][i5]<=s)
            {
                int ii[6];
                ii[1]=i1;ii[2]=i2;ii[3]=i3;ii[4]=i4;ii[5]=i5;
                for (int mask=0;mask<32;mask++)
                    if (check(mask,i+1)==1)
                    {
                        memset(cs,0,sizeof(cs));
                        for (int j=1;j<=5;j++)
                        {
                            if (getbit(mask,j-1)==0)
                                cs[j]=ii[j]+1;
                            else cs[j]=0;
                        }
                        dp[i+1][cs[1]][cs[2]][cs[3]][cs[4]][cs[5]]+=dp[i][i1][i2][i3][i4][i5];
                    }
            }
    long long ans=0;
        for (int i1=0;i1<=10;i1++)
        for (int i2=0;i2<=10;i2++)
        for (int i3=0;i3<=10;i3++)
        for (int i4=0;i4<=10;i4++)
        for (int i5=0;i5<=10;i5++)
            if (dt[i1][i2][i3][i4][i5]<=s)
            ans+=dp[10][i1][i2][i3][i4][i5];
   // cout<<ans<<endl;
    return ans;

}
void solve()
{
    setdt();
    cin>>t;
    for (int j=1;j<=5;j++)
        for (int i=1;i<=10;i++)
    {
        char x;cin>>x;
        A[i][j]=x-'0';
    }
    long long res=play(t)-play(t-1);
    cout<<res;
}
int main()
{
    freopen("color.inp","r",stdin);
    freopen("color.out","w",stdout);
    solve();
}
