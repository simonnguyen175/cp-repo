#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1505;

int n;
int a[N][N], bit[N][N];
ll f[N][N];

void update(int x, int y, int v){
    for (; y <= n; y += y&-y)
        bit[x][y] += v;
}

int get(int x, int y){
    int res = 0;
    for (; y >= 1; y -= y&-y)
        res += bit[x][y];
    return res;
}

bool ck(int x, int y){
    ll pre = f[x][y] + get(x, y);
    ll cur = f[x][y-1] + get(x, y-1) + a[x][y] + get(x, y);
    if ( x ) cur = max(cur, f[x-1][y] + get(x-1, y) + a[x][y] + get(x, y));

    return (pre == cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        f[i][j] = max(f[i][j-1], f[i-1][j]) + a[i][j];
        ans += f[i][j];
    }

    cout << ans << '\n';

    int q = 1;
    while ( q -- ){
        char type;
        int x, y, val;
        cin >> type >> x >> y;

        if ( type == 'U' ) val = 1;
        else val = -1;

        update(x, y, val);
        update(x, y+1, -val);

        int l = y, r = y;
        for (int i = y + 1; i <= n; i ++){
            bool tmp = ck(x, i);
            if ( tmp ) break;
            else{
                update(x, i, val);
                update(x, i+1, -val);
                r = i;
            }
        }
        ans += (r - l + 1) * val;

        for (int i = x + 1; i <= n; i ++){
            int pr = r;

            while ( r + 1 <= n ){
                if ( !ck(i, r+1) ){
                    update(i, r+1, val);
                    update(i, r+2, -val);
                    r ++;
                }
                else break;
            }

            while ( l <= r ){
                if ( ck(i, l) ) l ++;
            }

            if ( l <= r ){
                update(i, l, val);
                update(i, r+1, -val);
                ans += (r - l + 1) * val;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
