#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,s;
int x[100000];
bool noi3()
    {
        int s = 0;
        int t = 1;
        for(int i = 1; i <= n;i++)
            if(x[i] == a)
        {
            s++;t=i;break;
        }
        for(int i = t+1; i <= n;i++)
            if(x[i] == b)
        {
            s++;t=i;break;
        }
        for(int i = t+1; i <= n;i++)
            if(x[i] == c)
        {
            s++;t=i;break;
        }
        if(s==3)return true;
        else return false;
    }
bool noi2(int u, int v)
    {
        int s = 0;int t = 1;
        for(int i = 1; i <= n; i++)
            if(x[i] == u) {s++;t = i;break;}
        for(int i = t+1; i <= n; i++)
            if(x[i] == v) {s++;break;}
        if(s==2) return true;
        else return false;
    }
bool noi1(int u)
    {
        for(int i = 1; i <= n;i++)
        if(x[i] == u) return true;
        return false;
    }
int main()
    {
        //freopen("Wire4.inp","r",stdin);
        //freopen("Wire4.out","w",stdout);
        cin>>a>>b>>c>>n;
        for(int i = 1; i <= n;i++)
            cin>>x[i];
        if(noi3()) {cout<<3;return 0;}
        if(noi2(a,b) || noi2(a,c) || noi2(b,c)) {cout<<2;return 0;}
        if(noi1(a) || noi1(b) || noi1(c)) {cout<<1;return 0;}
        cout<<0;
        fclose(stdout);
        fclose(stdin);
    }
