#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;

int n, m, k;
ll f[N*10][N][20], a[N][20];
string s[N], way;

ll BIT(ll x, int k){
    return (x >> k) & 1;
}

void init(){
    cin >> m >> n >> k;

    for (int i = 1; i <= m; i ++)
        cin >> s[i], s[i] = ' '+ s[i];

    cin >> way;
    way = ' ' + way;

    int pn = n;
    n = (59 + n) /60 * 60;
    for (int i = 1; i <= m; i++)
        for (int j = pn + 1; j <= n; j++)
            s[i] = s[i] + '#';

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int l = (j + 59) / 60;
            int pos = (j - 1) / 60 + 1;
            ll val =  1LL << (l * 60 - j);
            if ( s[i][j] == '.') a[i][pos] +=  val, f[0][i][pos] += val;
        }
}

void solve(){
    for(int d = 1; d <= k; d ++)
        for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n/60; j ++){
            if ( ( way[d] == 'N' || way[d] == '?' ) && i < m )
                f[d][i][j] |= (f[d-1][i+1][j] & a[i][j]);

			if ( ( way[d] == 'S' || way[d] == '?' ) && i > 1 )
				f[d][i][j] |= (f[d-1][i-1][j] & a[i][j]);

			if ( ( way[d] == 'W' || way[d] == '?' ) ){
				ll tmp = ( (f[d-1][i][j] << 1)|BIT(f[d-1][i][j+1], 59) ) & a[i][j];
				f[d][i][j] |= tmp;
			 }

            if ( ( way[d] == 'E' || way[d] == '?' ) ){
				ll tmp = ((f[d-1][i][j] >> 1)|(BIT(f[d-1][i][j-1], 0) * (1LL << 59)) )& a[i][j];
				f[d][i][j] |= tmp;
			 }
	    }

    int ans = 0;
    for(int i = 1; i <= m; i ++)
        for(int j = 1; j <= n/60; j ++)
            ans +=  __builtin_popcountll(f[k][i][j]);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    init();
    solve();

    return 0;
}

