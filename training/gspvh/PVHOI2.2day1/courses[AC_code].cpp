#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const int M = 3e5 + 5;
const ll oo = 1e18;

int n, m;
ll a[N], s[M];
ll f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> s[i];

    for (int i = 1; i <= n+1; i ++)
    for (int j = 1; j <= n+1; j ++)
        f[i][j] = oo;

    f[n+1][0] = 0;
    for (int i = n; i >= 1; i --){
        f[i][0] = 0;
        for (int j = 1; j <= n - i + 1; j ++)
            f[i][j] = min(f[i+1][j], max(0LL, f[i+1][j-1] - a[i]));
    }

    for (int i = 1; i <= m; i ++)
        for (int j = n; j >= 0; j --)
            if ( s[i] >= f[1][j] ){
                cout << j << ' ';
                break;
            }

    return 0;
}
