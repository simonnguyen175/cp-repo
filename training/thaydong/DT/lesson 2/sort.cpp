#include<bits/stdc++.h>
#define simon "sort"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
using namespace std;

int m, n, s;
int a[10005][55], b[10005];
vector<int> col;

bool cmp(int x, int y) {
	for (auto i : col) {
		if ( a[x][i] < a[y][i] ) return true;
		else
			if ( a[x][i] > a[y][i] ) return false;
	}
    return ( x < y );
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> s;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= s; i ++){
        int x; cin >> x; col.pb(x);
    }

    reverse(col.begin(), col.end());

    for (int i = 1; i <= m; i ++)
        b[i] = i;

    sort(b + 1, b + 1 + m, cmp);

    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            cout << a[b[i]][j] << ' ';
        cout << '\n';
    }

    return 0;
}
