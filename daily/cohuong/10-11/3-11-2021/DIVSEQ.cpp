#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+1;
const int D = 1e6+1;

int t, d, n;
ll a[N], du[D];

int solve(int d){
    ll s=0;
    int res=0;
    memset(du, 0, sizeof du);
    du[0]=1;
    for (int i=1; i<=n; i++){
        s+=a[i];
        int e = s % d;
        res+=du[e];
        du[e]++;
    }
    return res;
}

int main(){
    freopen("DIVSEQ.inp","r",stdin);
    freopen("DIVSEQ.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++){
        cin >> d >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        cout << solve(d) <<'\n' ;
    }
    return 0;
}
