#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define ll long long
using namespace std;

int n, k;
ll a[51], s[51], cur;
bool f[51][51];

void xuli(int x){
    ll tmp = cur | (1LL<<x);

    memset(f, 0, sizeof f);

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++)
    for (int t = 0; t < i; t ++)
        f[i][j] |= f[t][j-1] & ( ((s[i]-s[t])&tmp) == tmp );

    if ( f[n][k] ) cur = tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("and.in", "r") ){
        freopen("and.in", "r", stdin);
        freopen("and.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    for (int i = 60; i >= 0; i --)
        xuli(i);

    cout << cur;

    return 0;
}
