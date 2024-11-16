#include<bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 2e18;

int n, k;
int p[25];

int get(int x){
    return n/x;
}

int mul(int a, int b){
    if ( a > oo/b ) return oo;
    else return a * b;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("PrimeMulti.inp", "r") ){
        freopen("PrimeMulti.inp", "r", stdin);
        freopen("PrimeMulti.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 0; i < k; i ++)
        cin >> p[i];

    int ans = 0;
    for (int i = 1; i < (1<<k); i ++){
        int tmp = 1;
        for (int j = 0; j < k; j ++) if ( (i>>j)&1 ) tmp = mul(tmp, p[j]);
        if ( __builtin_popcount(i) % 2 ) ans += get(tmp);
        else ans -= get(tmp);
    }

    cout << ans;

    return 0;
}
