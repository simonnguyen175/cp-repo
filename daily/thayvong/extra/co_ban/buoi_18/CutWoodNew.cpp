#include <bits/stdc++.h>
using namespace std;
#define N 500001

int n, t, k;
int pos[N];
long long s[N];
pair<long long, int> a[N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("CutWoodNew.inp","r",stdin);
    freopen("CutWoodNew.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    s[0]=0;
    for (int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i].first;
    for (int i=1; i<=n; i++)
        pos[a[i].second]=i;

    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> k;
        int t=pos[k];
        cout << s[n]-s[t]-(n-t)*a[t].first <<'\n';
    }
    return 0;
}
