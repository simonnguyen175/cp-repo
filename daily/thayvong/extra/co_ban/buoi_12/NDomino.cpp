#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100001];
int main()
    {
      //  freopen("NDomino.inp","r",stdin);
      //  freopen("NDomino.out","w",stdout);
        cin>>n;
        int s1 = 0; int s2 = 0;
        for(int i = 1; i <= n; i++)
            cin>>a[i].first>>a[i].second;
        for(int i = 1; i <= n; i++)
        {
            s1 = s1 + a[i].first;
            s2 = s2 + a[i].second;
        }
        int ans = abs(s1 - s2);
        for(int i = 1; i <= n; i++)
        {
            int x = s1 - a[i].first + a[i].second;
            int y = s2 - a[i].second + a[i].first;
            if(ans > abs(x-y)) ans = abs(x-y);
        }
        cout<<ans;
    }
