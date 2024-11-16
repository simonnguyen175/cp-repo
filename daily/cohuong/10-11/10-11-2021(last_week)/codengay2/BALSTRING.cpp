#include <bits/stdc++.h>
using namespace std;
string s;
int n,x;
map <vector<int>,int > mp;
int d[10][100005];
int c[10];
int res1,res2;
vector <int> vt;
void sub1()
{
    res1=res2=0;
    for (int i=1;i<=n;i++)
    {
        memset(c,0,sizeof c);
        for (int j=i;j<=n;j++){
            c[s[j]-'a']++;
            bool t=true;
            int p;
            for (int k=0;k<=7;k++) if (c[k]!=0){
                p=c[k];
                break;
            }
            for (int k=0;k<=7;k++) if (c[k]!=0 && c[k]!=p) t=false;
            if (t && j-i+1>res1){
                res1=j-i+1;
                res2=i-1;
            }
        }
    }
    cout<<res2<<' '<<res2+res1-1;
}
int getbit(int n,int i)
{
    return (n>>i)&1;
}
void solve(int u)
{
    mp.clear();
    memset(c,0,sizeof c);
    vt.clear();
    for (int i=0;i<x-1;i++) vt.push_back(0);
    mp[vt]=1;
    for (int i=1;i<=n;i++){
        c[s[i]-'a']++;
        int p=0;
        for (int j=0;j<x;j++){
            if (getbit(u,j)==1) {
                p=j;
                break;
            }
        }

        vt.clear();
        for (int j=p+1;j<x;j++){
            if (getbit(u,j)==1) {
                vt.push_back(c[j]-c[p]);
                p=j;
            }
        }
        for (int j=0;j<x;j++){
            if (getbit(u,j)==0) vt.push_back(c[j]);
        }          

        if (mp[vt]==0) mp[vt]=i+1;
        else {
            int v=mp[vt];
            if (res1<i-v+1){
                res1=i-v+1;
                res2=v-1;
            }
        }

    }
}
void sub2()
{
    x=0;
   for (int i=1;i<=n;i++) x=max(x,s[i]-'a');
   x++;
   for (int u=1;u<(1<<x);u++){
       solve(u);
   }
   cout<<res2<<' '<<res1+res2-1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BALSTRING.inp","r",stdin);
    freopen("BALSTRING.out","w",stdout);
    cin>>s;
    n=s.length();
    s=' '+s;
    if (n<=1000) {
        sub1();
        return(0);
    }
    sub2();


}
