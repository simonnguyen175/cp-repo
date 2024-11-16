#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;

int n;
struct cow{
    int w, s, v;

    bool operator < (const cow &x){
        if ( s + w == x.s + x.w ) return s < x.s;
        return s + w < x.s + x.w;
    }
} a[N];
ll f[N][20*N];


int main(){
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].w >> a[i].s >> a[i].v;
        mx = max(mx, a[i].s);
    }

    sort(a + 1, a + 1 + n);

    ll ans = 0;
    memset(f, 0 , sizeof f);

    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= mx; j ++){
        f[i+1][j] = max(f[i+1][j], f[i][j]);
        if ( j <= a[i+1].s )
            f[i+1][j+a[i+1].w] = max(f[i+1][j+a[i+1].w], f[i][j] + a[i+1].v);
        //cout << i + 1 << ' ' << j << ' ' << f[i+1][j] << " and " << i + 1 << ' ' << j + a[i+1].w << ' ' << f[i+1][j+a[i+1].w] << '\n';
        ans = max(ans, f[i+1][j+a[i+1].w]);
    }

    cout << ans;

    return 0;
}
