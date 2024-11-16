#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20;

int n, q;
int a[N], ans[N];

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        ans[i] = LLONG_MAX;
    for (int i = 1; i <= n; i ++){
        int cur = a[i];
        for (int j = i; j <= n; j ++){
            cur = lcm(cur, a[j]);
            ans[j-i+1] = min(ans[j-i+1], cur);
        }
    }

    while ( q -- ){
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}
