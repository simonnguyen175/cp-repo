#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n;
int a[N], pre[N], suf[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    pre[1] = 1;
    for (int i = 2; i <= n-1; i ++){
        if ( pre[i-1] >= a[i] ) pre[i] = a[i];
        else pre[i] = pre[i-1] + 1;
    }

    suf[n] = 1;
    for (int i = n-1; i >= 2; i --){
        if ( suf[i+1] >= a[i] ) suf[i] = a[i];
        else suf[i] = suf[i+1] + 1;
    }

//    cout << pre[9] << ' ' << suf[9] << '\n';

    int ans = 1;
    for (int i = 2; i <= n - 1; i ++)
        ans = max(ans, min(pre[i], suf[i]));

    cout << ans;

    return 0;
}
