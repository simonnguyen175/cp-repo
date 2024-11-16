#include<bits/stdc++.h>
#define simon "copypaste"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 105;
const ll MOD = 1e9 +7;
const int base = 31;

string s;
int t, n;
int dp[N], f[N][N];
ll Hash[N], Pow[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

ll getHash(int i, int j){
	return (Hash[j] - Hash[i - 1] * Pow [j - i + 1] + MOD * MOD ) % MOD;
}

void makeHash(){
    Pow[0] = 1;
    for (int i = 1; i <= n; i ++)
        Pow[i] = ( Pow[i-1] * base ) % MOD;
    for (int i = 1; i <= n; i ++)
        Hash[i] = ( Hash[i-1] * base + s[i] - 'a' + 1 ) % MOD;
}

void makeF(){
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = 0;
    string st;
    for (int i = n; i >= 1; i --){
		st = s[i] + st;
		int k, fail[N];
		k = 0, fail[1] = 0;
		string tmp = ' ' + st;
		for (int j = 2 ; j < tmp.size(); j ++){
			while ( tmp[k + 1] != tmp[j] && k > 0 ) k = fail[k];
			if ( tmp[k + 1] == tmp[j] ) k ++;
            fail[j] = k;

			if ( k <= j / 2 ) f[i][i + j - 1] = k;
			else{
                int l = fail[j - 1];
                while ( l > 0 && ( (l + 1 > j / 2) || (tmp[l + 1] != tmp[j]) ) )
                    l = fail[l];
                f[i][i + j - 1] = l + 1;
			}
		}
	}
}

void solve(){
    makeHash();
    makeF();

	vector<ll> clb[N];

	dp[1] = 1; dp[2] = 2; dp[3] = 3;

	for (int i = 4; i <= n; i++){
		map<ll, int> d;
		dp[i] = dp[i - 1] + 1;
		clb[i] = clb[i - 1];
		for (int j = 1; j <= i - 3; j++){
			ll hashf;
            int pos, res;
			bool c = 0;
			hashf = getHash(j, j + f[j][i] - 1);

			if ( f[j][i] == 0 || d[hashf] == 1 || f[j][i] == 1 ) continue;

			d[hashf] = 1;
		    pos = i - f[j][i];
			for (auto it : clb[pos])
                if ( it == hashf ) c = 1;

		    res = dp[pos] + 1;
			if ( !c )  res ++;

			if ( res == dp[i]) clb[i].pb(hashf);

			if ( res < dp[i] ){
                dp[i] = res;
                clb[i].clear();
                clb[i].pb(hashf);
			}
		}
	}

	cout << dp[n] << '\n';
}

int main(){
    file();
    cin >> t;
    while ( t -- ){
        cin >> s;
        n = s.size();
        s = ' ' + s;
        solve();
    }
    return 0;
}
