#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;

int n, q;
int a[N], Log[N];
pair<int, int> st[N][20];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    Log[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i/2] + 1;

    for (int i = 1; i <= n; i ++){
        st[i][0].first = a[i];
        st[i][0].second = a[i];
    }

    for (int j = 1; j <= Log[n]; j ++)
        for (int i = 1; i + ( 1 << j ) - 1<= n; i ++){
            st[i][j].first = min(st[i][j-1].first, st[i + ( 1 << (j - 1) )][j-1].first);
            st[i][j].second = max(st[i][j-1].second, st[i + ( 1 << (j - 1) )][j-1].second);
        }

    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        int j = Log[v - u + 1];
        cout << u << ' ' << v - (1 << j) + 1 <<' '<<j << '\n';
        cout << st[u][j].first <<' '<<st[v - (1 << j) + 1][j].first << '\n';
        cout << max(st[u][j].second, st[v - (1 << j) + 1][j].second) - min(st[u][j].first, st[v - (1 << j) + 1][j].first) << '\n';
    }

    return 0;
}
