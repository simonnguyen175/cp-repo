#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int n, m;
int h[N], nxt[2*N][35];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("jump.inp", "r") ){
        freopen("jump.inp", "r", stdin);
        freopen("jump.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];

    deque<int> dq;
    for (int i = n; i >= 1; i --){
        while ( dq.size() && h[dq.back()] < h[i] ) dq.pop_back();
        if ( dq.size() )  nxt[i][0] = dq.back();
        dq.push_back(i);
    }

    dq.clear();
    for (int i = 1; i <= n; i ++){
        while ( dq.size() && h[dq.back()] > h[i] ) dq.pop_back();
        if ( dq.size() ) nxt[i+n][0] = dq.back() + n;
        dq.push_back(i);
    }

    for (int i = 1; i <= n; i ++) if ( !nxt[i][0] ) nxt[i][0] = i + n;
    for (int i = n + 1; i <= 2*n; i ++) if ( !nxt[i][0] ) nxt[i][0] = i - n;

    for (int j = 1; j <= 30; j ++)
    for (int i = 1; i <= 2*n; i ++)
        nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    for (int i = 1; i <= m; i ++){
        int x, k;
        cin >> x >> k;

        for (int j = 30; j >= 0; j --)
            if ( BIT(k, j) ) x = nxt[x][j];

        if ( x > n ) cout << x - n << '\n';
        else cout << x << '\n';
    }

    return 0;
}
