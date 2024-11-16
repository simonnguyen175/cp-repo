#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 305;
const int MOD = 1e9 + 7;

int n;
int f[N][N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    f[2][1][2] = 1;
    int ans = 0;
    for (int s = 2; s <= n; s ++)
    for (int l = 1; l <= n; l ++)
    for (int r = l+1; r <= n; r ++) if ( f[s][l][r] ){
        int val = f[s][l][r];

        if ( s == n ){
            ans = add(ans, val);
            continue;
        }

        for (int mid = l+1; mid <= r; mid ++)
            f[s+1][mid][r+1] = add(f[s+1][mid][r+1], val);

        for (int mid = l+1; mid <= r; mid ++)
            f[s+1][l][mid] = add(f[s+1][l][mid], val);

        if ( l == 1 ) f[s+1][l][r+1] = add(f[s+1][l][r+1], val);
        if ( r == s ) f[s+1][l][r+1] = add(f[s+1][l][r+1], val);
    }

    cout << ans;

    return 0;
}
