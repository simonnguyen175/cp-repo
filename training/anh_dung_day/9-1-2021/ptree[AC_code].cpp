#include <bits/stdc++.h>

using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define read(A) freopen((A + ".in").c_str(),"r",stdin)
#define write(A) freopen((A + ".out").c_str(),"w",stdout)
#define ll long long
#define pb push_back
#define ull unsigned long long
#define int long long
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
const int DFS_WHITE = 0;
const int DFS_BLACK = 1;
const int INF = 1e18 + 5;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

void setIO(string filename = ""){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	if(filename.size() == 0)
		return;
	read(filename);
	write(filename);
}



int n, m;
int ans = 0;
int dp[MAXN];
int dp2[MAXN];
vector<vi> AdjList;
vector<int> ps[MAXN], ss[MAXN];


void dfs(int u, int p = -1) {
    dp[u] = 1;

    for(int i = 0; i <= AdjList[u].size() + 3; i++) {
        ps[u].pb(1);
        ss[u].pb(1);
    }

    for(int i = 1; i <= AdjList[u].size(); i++) {
        int v = AdjList[u][i - 1];
        ps[u][i] = ps[u][i - 1];

        if(v == p) continue;

        dfs(v, u);
        dp[u] *= (1 + dp[v]);
        dp[u] %= m;

        ps[u][i] *= (1 + dp[v]);
        ps[u][i] %= m;
    }

    for(int i = AdjList[u].size(); i >= 1; i--) {
        int v = AdjList[u][i - 1];
        ss[u][i] = ss[u][i + 1];

        if(v == p) continue;

        ss[u][i] *= (1 + dp[v]);
        ss[u][i] %= m;

    }


}

void dfs2(int u, int p = -1){
	for (int i=1; i<=AdjList[u].size(); i++){
		int v = AdjList[u][i - 1];
		//		cout<<u<<" "<<i<<" "<<v<<" "<<AdjList[u]<<endl;
		if (v != p){
			dp2[v] = ((ps[u][i - 1] * ss[u][i + 1]) % m * dp2[u] % m + 1) % m;
			dfs2(v, u);
		}
	}
}

void solve(){
	cin>>n>>m;
	AdjList.assign(n + 1, vi());
	for (int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	dfs(1);
	dp2[1] = 1;
	dfs2(1);
	for (int i=0; i<ps[1].size(); i++){
	//	cout<<ps[1][i]<<endl;
	}

	for (int i=1; i<=n; i++)
        cout<<dp[i]<<' '<<dp2[i]<<'\n';

	for (int i=1; i<=n; i++){
		cout<<(dp[i] * dp2[i]) % m<<endl;
	}
}

signed main() {
	setIO();
	int test = 1;
//	cin>>test;
	while(test--){
		solve();
		if (test)
			cout<<endl;
	}
}
