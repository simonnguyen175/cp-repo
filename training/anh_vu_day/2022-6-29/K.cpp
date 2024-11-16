#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], x[3*N], y[3*N], vis[N];

bool check(int turn){
    for (int i = 1; i <= n; i ++) b[i] = a[i], vis[i] = 0;
    for (int i = 1; i <= turn; i ++)
        swap(b[x[i]], b[y[i]]);

    int cnt = 0;
    for (int i = 1; i <= n; i ++) if ( !vis[b[i]] ){
        cnt ++;
        while ( b[i] != i ){
            vis[b[i]] = 1;
            swap(b[i], b[b[i]]);
        }
    }

    return ( n - cnt ) <= turn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sorting.inp", "r") ){
        freopen("sorting.inp", "r", stdin);
        freopen("sorting.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> x[i] >> y[i];

    int lo = 1, hi = m, res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res;

    return 0;
}
