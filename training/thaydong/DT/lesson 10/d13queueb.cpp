#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, k, sz;
int h[N], del[N], cdel[320];
pi mx[320][N];

int add(int a, int b){
    a += b;
    if ( a >= k ) a -= k;
    if ( a < 0 ) a += k;
    return a;
}

pi combine(pi a, pi b){
    if ( b.fi > a.fi ) return b;
    return a;
}

void upd(int i){
    for (int j = 0; j < k; j ++) mx[i][j] = {0, 0};
    int c = 0;
    for (int j = (i-1)*sz; j < min(n, i*sz); j ++){
        if ( !del[j] ){
            mx[i][c] = combine(mx[i][c], {h[j], j});
            c = add(c, 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> h[i];

    sz = sqrt(n)+1;
    int cbl = ( n % sz ? n/sz + 1 : n/sz );
    for (int i = 1; i <= cbl; i ++)
        upd(i);

    int t = n, msz = sz%k;
    while ( t -- ){
        // tim max
        int cnt = 0;
        pi ans = {0, 0};
        for (int i = 1; i <= cbl; i ++){
            int r = add(k, -cnt);
            ans = combine(ans, mx[i][r]);
            cnt = add(cnt, add(msz, -cdel[i]));
        }

        cout << ans.fi << ' ';

        // cap nhat
        del[ans.se] = 1;
        cdel[ans.se/sz+1] = add(cdel[ans.se/sz+1], 1);
        upd(ans.se/sz+1);
    }

    return 0;
}
