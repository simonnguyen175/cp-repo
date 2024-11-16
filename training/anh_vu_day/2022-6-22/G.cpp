#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int oo = 1e9;

int n, k;
int a[N], cnt[N][2], f[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= k; i ++)
    for (int j = i; j <= n; j += k)
        if ( ( a[i] + a[j] ) % 2 ) cnt[i][1] ++;
        else cnt[i][0] ++;

    f[0][0] = 0, f[0][1] = oo;
    for (int i = 1; i <= k; i ++) if ( a[i] % 2 ){
        f[i][0] = min(f[i-1][0] + cnt[i][1], f[i-1][1] + cnt[i][0]);
        f[i][1] = min(f[i-1][0] + cnt[i][0], f[i-1][1] + cnt[i][1]);
    }
    else{
        f[i][0] = min(f[i-1][0] + cnt[i][0], f[i-1][1] + cnt[i][1]);
        f[i][1] = min(f[i-1][0] + cnt[i][1], f[i-1][1] + cnt[i][0]);
    }

    cout << f[k][0];

    return 0;
}
