#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 5;
const ll oo = 4e9;

int n;
int a[N];
ll s[N];

ll add(int a, int b){
    if ( a > oo - b ) return oo;
    else return a + b;
}

ll mul(int a, int b){
    if ( !a || !b ) return 0;
    if ( a > oo / b ) return oo;
    else return a * b;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());

    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + a[i];

    ll ans = oo;
    for (int i = 1; i <= n; i ++){
        ll tmp = 1ll * (i-1) * 3600;
        for (int j = 1, cur = 0; j <= n; j += i, cur ++)
            tmp = add(tmp, mul(s[min(n, j+i-1)] - s[j-1], (1ll<<cur)));

        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}
