#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int h, w;
int a[N][N], up[N][N], l[N], r[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> h >> w;
    for (int i = 1; i <= h; i ++)
    for (int j = 1; j <= w; j ++){
        char x;
        cin >> x;
        if ( x == '.' ) a[i][j] = 0;
        else a[i][j] = 1;
    }

    for (int j = 1; j < w; j ++) up[1][j] = 1;
    for (int i = 2; i <= h; i ++)
    for (int j = 1; j <= w; j ++){
        up[i][j] = 1;
        if ( ( a[i][j] == a[i-1][j] && a[i][j+1] == a[i-1][j+1] )
          || ( a[i][j] == !a[i-1][j] && a[i][j+1] == !a[i-1][j+1] ) )
            up[i][j] = up[i-1][j] + 1;
//        cout << i << ' ' << j << ' ' << up[i][j] << '\n';
    }

    int ans = max(h, w);
    for (int i = 1; i <= h; i ++){
        stack<int> stk;
        for (int j = 1; j < w; j ++){
            while ( stk.size() && up[i][stk.top()] >= up[i][j] ) stk.pop();
            if ( !stk.size() ) l[j] = 1;
            else l[j] = stk.top()+1;
            stk.push(j);
        }

        while ( stk.size() ) stk.pop();

        for (int j = w-1; j >= 1; j --){
            while ( stk.size() && up[i][stk.top()] >= up[i][j] ) stk.pop();
            if ( !stk.size() ) r[j] = w-1;
            else r[j] = stk.top()-1;
            stk.push(j);
        }

        for (int j = 1; j < w; j ++)
            ans = max(ans, up[i][j] * (r[j] - l[j] + 2));
    }

    cout << ans << '\n';

    return 0;
}
