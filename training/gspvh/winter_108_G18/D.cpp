#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int k, n;
string s;
int go[N][31];
char t[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("slom.inp", "r", stdin);
    freopen("slom.out", "w", stdout);

    cin >> k;
    cin >> s;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
        if ( i % 2 ) go[i][0] = (i+1)/2;
        else go[i][0] = n - (i-1)/2;

    for (int j = 1; j <= __lg(k); j ++)
    for (int i = 1; i <= n; i ++)
        go[i][j] = go[go[i][j-1]][j-1];

    for (int i = 1; i <= n; i ++){
        int cur = i;

        for (int j = 0; j <= 30; j ++) if ( BIT(k, j) )
            cur = go[cur][j];

//        cout << i << " -> " << cur << '\n';

        t[cur] = s[i];
    }

    for (int i = 1; i <= n; i ++)
        cout << t[i];

    return 0;
}
