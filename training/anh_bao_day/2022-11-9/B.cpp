#include<bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e15;
const int N = 20;

int n;
int a[N], f[N][N][N][N];

int calc(int l, int r, int cl, int cr){
    if ( l + 1 == r ) return 0;
    if ( f[l][r][cl][cr] != -1 ) return f[l][r][cl][cr];
    int res = oo;
    for (int i = l+1; i < r; i ++)
        res = min(res, calc(l, i, cl, cl+cr) + calc(i, r, cl+cr, cr) + a[i] * (cl+cr));
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    memset(f, -1, sizeof f);
    cout << a[1] + a[n] + calc(1, n, 1, 1);

    return 0;
}
