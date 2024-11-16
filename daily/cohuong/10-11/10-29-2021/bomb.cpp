#include<bits/stdc++.h>
#define simon "bomb"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 35;

int m, n;
ll ans = 0;
int a[N][N], b[N][N];

bool check(int x, int y) {
	if ( a[x][y] == -1 ) return true;
	if ( ( b[x-1][y] + b[x+1][y] + b[x][y-1] + b[x][y+1] ) % 2 == a[x][y] ) return true;
	return false;
}

bool ok(){
	for (int i = 1; i <= n; i ++)
        if ( !check(m, i) ) return false;
    /*
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
    cout << "---------------" << '\n';
        */
	return true;
}

void gen(int u, int v) {
	for (int i = 0; i <= 1; i ++){
		b[u][v] = i;
		if ( u > 1 && !check(u-1, v) ) continue;
		if ( u == m && v == n ) ans += ok();
		else{
            if ( v == n ) gen(u+1, 1);
			else gen(u, v+1);
		}
	}
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    gen(1, 1);

    cout << ans;

    return 0;
}

