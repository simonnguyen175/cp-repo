#include<bits/stdc++.h>
using namespace std;
int n, a[200002], u, v, k, s = 0, ans;
int main()
    {
        cin>>n>>k;
        for(int i = 1; i <= 2 * n; i++)
            cin>>a[i];
        for(int i = 1; i <= 2 * n - 2 * k; i++)
        {
            u = i; v = i + 2 * k - 1;
            for(int j = i; j <= i + k - 1; j++)
            {
                if(a[u] == a[v]) s = s + 2 * a[u];
                u++; v--;
            }
            if(s > ans) ans = s;
            s = 0;
        }
        cout<<ans;
    }
