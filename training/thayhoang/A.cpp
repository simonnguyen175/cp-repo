#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, q;
ll a[2][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[0][i];
    sort(a[0] + 1, a[0] + 1 + n, greater<int>());
    int t = 0;
    while ( q -- ){
        int x, y;
        cin >> x >> y;
        int i = 1, j = y + 1, cur = 0;
        while ( i <= y && j <= n ){
            if ( a[t][i] - x >= a[t][j] ) a[t^1][++cur] = a[t][i] - x, i ++;
            else a[t^1][++cur] = a[t][j], j ++;
        }

        for (; i <= y; i ++) a[t^1][++cur] = a[t][i] - x;
        for (; j <= n; j ++) a[t^1][++cur] = a[t][j];
        t ^= 1;
    }

    for (int i = 1; i <= n; i ++)
        cout << a[t][i] << ' ';

    return 0;
}
