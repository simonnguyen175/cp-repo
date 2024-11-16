#include<bits/stdc++.h>
using namespace std;

double dc(int x, int y){
    return (double)sqrt(1ll*abs(x-y)*abs(x-y) + w*w);
}

void solve(){
    cin >> l >> w;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> b[i];

    for (int i = 1; i <= n; i ++)
    for (int j = i; j <= n; j ++)
    for (int k = 1; k <= m; k ++)
    for (int t = k; t <= m; t ++){
        double tmp = 1.0 * (a[j] - a[i]) +  1.0 * (b[t] - b[k]) + dc(a[j], a[i]) + dc(b[t], b[k]);
        if ( )
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
