#include<bits/stdc++.h>
using namespace std;
int n, m, a[100001], b[100001];
int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        for(int i = 1; i <= m; i++)
            cin>>b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + m);
        while(n > 0 && m > 0)
        {
            if(a[n] == b[m]) {cout<<a[n] * 2; return 0;}
            if(a[n] < b[m]) m--;
            if(a[n] > b[m]) n--;
        }
        cout<<"No";
    }
