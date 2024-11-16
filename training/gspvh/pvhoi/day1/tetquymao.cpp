#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int row[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int col[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int MOD = 1e9 + 19972207;

int r, c;
int a[65];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

namespace sub1{
    int b[65][65], cnt[65];
    ll ans[65][65];

    bool inside(int x, int y){
        return ( x >= 1 && x <= r && y >= 1 && y <= c );
    }

    bool ck(int x, int y){
        for (int j = 0; j < 4; j ++){
            int nx = x + row[j], ny = y + col[j];
            if ( inside(nx, ny) && b[nx][ny] ) return 0;
        }
        return 1;
    }

    void gen(int x, int y){
        for (int i = 0; i <= 1; i ++){
            if ( i && !ck(x, y) ) continue;

            b[x][y] = i;
            cnt[x] += i;

            if ( y < c ) gen(x, y + 1);
            else if ( x < r ){
                if ( a[x] == 3 || (a[x] < 3 && cnt[x] % 3 == a[x]) )
                    gen(x + 1, 1);
            }
            else if ( a[x] == 3 || (a[x] < 3 && cnt[x] % 3 == a[x]) ){
                for (int j = 1; j <= r; j ++)
                for (int k = 1; k <= c; k ++) if ( b[j][k] )
                    ans[j][k] ++;
            }

            cnt[x] -= i;
        }
    }

    void solve(){
        memset(b, 0, sizeof b);
        gen(1, 1);

        for (int i = 1; i <= r; i ++){
            for (int j = 1; j <= c; j ++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
}

namespace sub2{
    int pre[65], suf[65];

    void solve(){
        pre[0] = 1;
        for (int i = 1; i <= r; i ++){
            if ( a[i] == 3 ) pre[i] = mul(pre[i-1], 2);
            else if ( a[i] <= 1 ) pre[i] = pre[i-1];
            else pre[i] = 0;
        }

        suf[r+1] = 1;
        for (int i = r; i >= 1; i --){
            if ( a[i] == 3 ) suf[i] = mul(suf[i+1], 2);
            else if ( a[i] <= 1 ) suf[i] = suf[i+1];
            else suf[i] = 0;
        }

        for (int i = 1; i <= r; i ++){
            if ( a[i] )
                cout << mul(pre[i-1], suf[i+1]) << '\n';
            else cout << 0 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("tetquymao.inp", "r", stdin);
    freopen("tetquymao.out", "w", stdout);

    cin >> r >> c;
    for (int i = 1; i <= r; i ++)
        cin >> a[i];

    if ( r * c <= 21 ) { sub1::solve(); return 0; }

    if ( c == 1 ) { sub2::solve(); return 0; }

    return 0;
}
