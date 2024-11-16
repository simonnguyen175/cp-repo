#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7;
const int MOD = 1e9 + 7;

int m, n, tt = 0;
int p[N], d[N];
int ans = 1;

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void solve(int l, int r, int bit){
    if ( !ans ) return;

    if ( l == r ) return;

    tt ++;
    int mid = l + r >> 1;
    for (int i = l; i <= mid; i ++)
        d[p[i]] = tt;
    bool ck = 0;
    for (int i = mid+1; i <= r; i ++)
        if ( d[p[i]] == tt ) { ck = 1; break; }

    if ( ck ){
        for (int i = l; i <= mid; i ++)
            if ( p[i] != p[i+(1<<bit)] ){
                ans = 0; return;
            }
        ans = mul(ans, 2);
        solve(l, mid, bit-1);
    }
    else{
        solve(l, mid, bit-1);
        solve(mid+1, r, bit-1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < (1<<m); i ++)
        cin >> p[i];

    solve(0, (1<<m)-1, m-1);

    cout << ans;

    return 0;
}
