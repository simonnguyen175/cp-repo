#include <bits/stdc++.h>
using namespace std;
int n,i,ans,t;
string st;
int main()
{
    freopen("selectball.inp","r",stdin);
    freopen("selectball.out","w",stdout);
    cin >> n;
    cin >> st ;
    ans=0;
    t=0; st=' '+st+'R'; n++;
    for (int i=0; i<=n; i++)
        if (st[i]== 'R')
                {
                    ans=max(ans,i-t-1);
                    t=i;
                }
    st[n]='B'; t=0;
    for (int i=0; i<=n; i++)
        if (st[i]== 'B')
                {
                    ans=max(ans,i-t-1);
                    t=i;
                }
    st[n]='Y'; t=0;
    for (int i=0; i<=n; i++)
        if (st[i]== 'Y')
                {
                    ans=max(ans,i-t-1);
                    t=i;
                }
    cout << ans;
}
