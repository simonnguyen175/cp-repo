#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 105;

int n, k, t;
string f[N][N][10], a[N];

bool cmp(string x, string y){
	return (x + y) > (y + x);
}

int calcmod(string x){
	int res = 0;
	for(int i = 0; i < x.size(); i ++)
        res += (x[i] - '0');
	return res;
}

string getMax(string x, string y){
	if( x == "#" || x.size() < y.size() )  return y;
	if( x.size() == y.size() )
		if ( x < y) return y;
    return x;
}

void solve(){
	sort(a + 1, a + 1 + n, cmp);

	for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= k; j ++)
            for(int d = 0; d <= 8; d ++)
                f[i][j][d] = "#";

	f[0][0][0] = "";
	for(int i = 0; i < n; i ++)
		for(int j = 0; j <= k; j ++)
			for(int d = 0; d <= 8; d ++){
				if( f[i][j][d] == "#" ) continue;
                f[i+1][j][d] = getMax(f[i+1][j][d], f[i][j][d]);
                //cout << i + 1 << ' ' << j << ' ' << d << ' ' << f[i+1][j][d] << '\n';
                int nd = ( d + calcmod(a[i+1]) ) % 9;
                f[i+1][j+1][nd] = getMax(f[i+1][j+1][nd], f[i][j][d] + a[i+1]);
                //cout << i + 1 << ' ' << j + 1 << ' ' << nd << ' ' << f[i+1][j][d] << '\n';
		    }

	if ( f[n][k][0] == "#" ) cout << -1 << '\n';
	else cout << f[n][k][0] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- ){
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        solve();
    }
    return 0;
}