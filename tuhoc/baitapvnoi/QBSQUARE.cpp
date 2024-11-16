#include <bits/stdc++.h>
using namespace std;
#define MAX   1111
int a[MAX][MAX];
int f[MAX][MAX];
int m,n;
int min(int x,int y,int z)
{
    int m;
    m=x;
    if (y<m) m=y;
    if (z<m) m=z;
    return (m);
}
void init(void)
{
     int i,j;
     scanf("%d",&m);
     scanf("%d",&n);
     for (i=1;i<=m;i=i+1)
         for (j=1;j<=n;j=j+1)
             scanf("%d",&a[i][j]);
}
void optimize(void)
{
     int i,j,s,r;
     for (i=1;i<=m;i=i+1) f[i][1]=1;
     for (i=1;i<=n;i=i+1) f[1][i]=1;
     for (i=2;i<=m;i=i+1)
         for (j=2;j<=n;j=j+1)
             {
              s=a[i][j]+a[i][j-1]+a[i-1][j]+a[i-1][j-1];
              if (s*(s-4)==0) f[i][j]=min(f[i][j-1],f[i-1][j],f[i-1][j-1])+1;
              else f[i][j]=1;
             }
     r=0;
     for (i=1;i<=m;i=i+1){
         for (j=1;j<=n;j=j+1){
            if (r<f[i][j]) r=f[i][j];
            cout << f[i][j] <<' ';
          }
        cout <<'\n';
     }
     printf("%d\n",r);
}
int main(void)
{
    freopen("QBSQUARE.INP","r",stdin);
    freopen("QBSQUARE.OUT","w",stdout);
    init();
    optimize();
}
