#include <bits/stdc++.h>
using namespace std;
int n,a,vs[102],F[102][102][102],ok[102][102][102];
vector <int> Px,Py;
struct point
{
    int x,y;
    bool operator < (const point &a)
    const
    {
        if (y!=a.y) return (y>a.y);
        return (x>a.x);
    }
};
point A[102];
void compress()
{

    for (int i=1;i<=n;i++)
    {
        Px.push_back(A[i].x);
        Py.push_back(A[i].y);
    }
    sort(Px.begin(),Px.end());
    sort(Py.begin(),Py.end());
}
void solve()
{
    cin>>n>>a;
    for (int i=1;i<=n;i++)
    {
        cin>>A[i].x>>A[i].y;
    }
    compress();
    for (int l=0;l<=Px.size();l++)
        for (int r=0;r<=Px.size();r++)
            for (int y=0;y<=Py.size();y++)
    {
        if (l>r) {F[l][r][y]=0;continue;}
        if (y==Py.size()) {F[l][r][y]=0;continue;}
        F[l][r][y]=1e9;
    }
    memset(ok,0,sizeof(ok));
    for (int l=0;l<Px.size();l++)
        for (int r=l;r<=Px.size();r++)
            for (int y=0;y<Py.size();y++)
    {
        int vx=Px[r]-Px[l];
        if (vx*Py[y]>a) break;
        int yy=y;
        for (int i=y;i<Py.size();i++)
            if (vx*Py[y]<=a) yy=i;
        for (int i=1;i<=n;i++)
            if (A[i].x>=Px[l]&&A[i].x<=Px[r]&&A[i].y>=Py[y]&&A[i].y<=Py[yy])
        {
            ok[l][r][y]=1;
            break;
        }
    }
    for (int l=Px.size()-1;l>=0;l--)
        for (int r=l;r<Px.size();r++)
            for (int y=Py.size()-1;y>=0;y--)
    {
        int yy=y;
        for (int x=l;x<=r;x++)
        {
            int vx=Px[r]-Px[x];
            if (vx>a) continue;
            if (vx*Py[yy]>a) continue;
            //F[l][r][y]=min(F[l][r][y],F[l][x-1][y]+F[x][r][yy+1]+1);
            while (yy<Py.size()-1&&vx*Py[yy+1]<=a)
            {
                yy++;

            }
            if (ok[x][r][y]==1) F[l][r][y]=min(F[l][r][y],F[l][x-1][y]+F[x][r][yy+1]+1);
            else F[l][r][y]=min(F[l][r][y],F[l][x-1][y]+F[x][r][yy+1]);
        }
    }
    cout<<F[0][Px.size()-1][0];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("rectcover.in","r",stdin);
    freopen("rectcover.out","w",stdout);
    solve();
}

