#include<bits/stdc++.h>
#define simon "triangles"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e3 + 5;

int n, h[N][N], r[N][N], l[N][N];
ll ans = 0;
char a[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( a[i][j] == '#' ) h[i][j] = h[i-1][j] + 1;
            else h[i][j] = 0;

	for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( h[i][j] > l[i][j-1] ) l[i][j] = l[i][j-1] + 1;
            else l[i][j] = min(l[i][j-1] , h[i][j] - 1) + 1;

	for (int i = 1; i <= n; i ++)
        for (int j = n; j >= 1; j --)
            if ( h[i][j] > r[i][j+1] ) r[i][j] = r[i][j+1] + 1;
            else r[i][j] = min(r[i][j+1], h[i][j] - 1) + 1;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            //cout << i << ' ' << j << ' ' << l[i][j] << ' ' << r[i][j] << '\n';
            ans += min(l[i][j], r[i][j]);
        }

	cout << ans;

	return 0;
}



