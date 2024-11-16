#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+1;
const int oo=1e15;

int n, h, a[N];
long long s[N], mark[N], ans=oo;

int main(){
    freopen("INCREASING.inp","r",stdin);
    freopen("INCREASING.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> h;
    long long t=(h+1)*h/2;
    for (int i=1; i<=n; i++) cin >> a[i], s[i]=s[i-1]+a[i];
    memset(mark, 0, sizeof mark);
    for (int i=1; i<=n; i++)
        if ( a[i] > 1 ){
            int g=max(i-a[i]+2, i-h+1);
            if ( g < 0 ){
                mark[0]+=1; mark[i+1]=-1;
            }
            else{
                mark[g]+=1; mark[i+1]-=1;
            }
        }
    for (int i=0; i<=n; i++)
        mark[i]+=mark[i-1];
    for (int i=1; i<=n; i++)
        if ( mark[i] == 0 )
            ans=min(ans, t-s[i+h-1]+s[i-1]);
    if ( ans == oo ) cout << -1;
    else cout << ans;
    return 0;
}
