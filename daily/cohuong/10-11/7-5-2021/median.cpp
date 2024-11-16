#include<bits/stdc++.h>
#define simon "median"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;

int m, n, r, c;
int a[N][N], f[N][N];
vector<int> b, med;

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int get(int i, int j){
	return f[i][j] - f[i-r][j] - f[i][j-c] + f[i-r][j-c];
}

bool check(int x){
	for (int i = 1; i <= m ; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (a[i][j] <= x);

	for (int i = r ; i <= m ; i++)
        for (int j = c ; j <= n ; j++)
            if ( get(i, j) >= r*c/2 + 1) return true;

	return false;
}

void init(){
    file();
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    sort(b.begin(), b.end());
    med.push_back(b[0]);
    for (int i = 1; i < b.size(); i ++)
        if ( b[i] != b[i-1] ) med.push_back(b[i]);
}

void solve(){
    int l = 0, r = med.size() - 1, res;
    while ( l <= r ){
        int mid = ( l + r ) / 2;
        if  ( check(mid) ){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
}

int main(){
    init();
    solve();
    return 0;
}
