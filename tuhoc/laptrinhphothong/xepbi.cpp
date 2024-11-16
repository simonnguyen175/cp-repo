#include<bits/stdc++.h>
using namespace std;
int a[1000001], c[1000001], n, m, s = 0, t = 0, ct;
int main()
{
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int i = 1; i <= n; i++)
            cin>>c[i];
        ct= c[1];
        for(int i = 1; i <= n; i++)
        {
            if(ct != c[i]) {s++; ct = c[i]; t = 0;}
            if(t + a[i] > m) {s++; ct = c[i]; t = 0;}
            t = t + a[i];
        }
        if(s > 0) cout<<s + 1;
        else cout<<-1;
}
