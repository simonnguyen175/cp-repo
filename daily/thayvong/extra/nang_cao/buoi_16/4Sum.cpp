#include <bits/stdc++.h>
using namespace std;
const int N=501;

struct t{
    int m;
    int n;
    int p;
    int q;
};

int a, b, c, d;
int xa[N], xb[N], xc[N], xd[N], s[N];
t ans;
map<int, int> be;

int main(){
    freopen("4Sum.inp","r",stdin);
    freopen("4Sum.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> a >> b >> c >> d;
    for (int i=1; i<=a; i++) cin >> xa[i];
    for (int i=1; i<=b; i++) cin >> xb[i];
    for (int i=1; i<=c; i++) cin >> xc[i];
    for (int i=1; i<=d; i++) cin >> xd[i];
    int ns=0;
    for (int i=1; i<=a; i++)
        for (int j=1; j<=b; j++){
            be[xa[i]+xb[j]]=1;
        }
    int tmp;
    for (int i=1; i<=c; i++)
        for (int j=1; j<=d; j++)
            if ( be[0-xc[i]-xd[j]]){
                ans.p=xc[i]; ans.q=xd[j];
                tmp= 0-xc[i]-xd[j];
            }
    for (int i=1; i<=a; i++)
        for (int j=1; j<=b; j++)
            if ( xa[i] + xb[j] == tmp ){
                ans.m=xa[i];
                ans.n=xb[j];
            }
    cout << ans.m <<' '<<ans.n <<' '<<ans.p<<' '<<ans.q;
    return 0;
}

