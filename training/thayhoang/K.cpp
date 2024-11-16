#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n, m;
int a[N], b[N];
map<int, pi> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> b[i];

    int i = 0, j = 0;
    d[0] = {0, 0};
    int cur = 0;

    while ( i < n && j < m ){
        if ( cur > 0 ) cur -= b[++j];
        else cur += a[++i];

        if ( d.find(cur) != d.end() ){
            cout << i - d[cur].fi << '\n';
            for (int t = d[cur].fi + 1; t <= i; t ++)
                cout << t - 1 << ' ';
            cout << '\n';
            cout << j - d[cur].se << '\n';
            for (int t = d[cur].se + 1; t <= j; t ++)
                cout << t - 1 << ' ';
            cout << '\n';
            break;
        }
        else d[cur] = {i, j};
    }

    return 0;
}
