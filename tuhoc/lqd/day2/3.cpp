#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;

int l, n;
int a[20];
pi ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("3.inp", "r") ){
        freopen("3.inp", "r", stdin);
        freopen("3.out", "w", stdout);
    }

    cin >> l >> n;

    for (int i = 1; i <= n; i ++) cin >> a[i];

    ans = {1, 0};

    int cnt;
    ll tmp;

    for (int i = 1; i <= l; i ++)
    for (int c = 1; c <= 9; c ++){
        cnt = 0, tmp = 1;
        for (int j = 1; j <= n; j ++){
            tmp = 0;
            for (int k = 1; k <= i; k ++)
                tmp = ( tmp * 10 + c ) % a[j];
            if ( tmp == 0 ) cnt ++;
        }
        if ( cnt >= 2 ) ans = {i, c};
    }

    cout << ans.fi << ' ' << ans.se;

    return 0;
}
