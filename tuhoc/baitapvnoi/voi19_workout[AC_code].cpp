#include<bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define bit(s, i) (s & (1<<i))

using namespace std;

const int N = 1e5 + 5;
const int M = 1;
const int K = 1;
const int mod = 1e9+7;
const int inf = 2e9;
const long long Inf = 2e18;

typedef long long ll;
typedef pair < ll, int > ii;

int n, m, k, st[N][2];

int b[N];
vector < ii > adj[N];

ll d[N][11][2];

void dic(int h, int t) {
	priority_queue < ii, vector < ii >, greater < ii > > q;
	for(int i=1;i<=n;++i) d[i][h][t] = Inf;

	d[st[h][t]][h][t] = 0;
	q.push({0, st[h][t]});

	while(q.size()) {
		ii top = q.top();
		q.pop();

		ll pd = top.fi;
		int p = top.se;

		if(d[p][h][t] != pd) continue;

		for(ii x : adj[p]) if(d[x.fi][h][t] > pd + x.se) {
			d[x.fi][h][t] = pd + x.se;
			q.push({pd + x.se, x.fi});
		}
	}
}

struct edge {
	int u, v, w;
} ed[N];

vector < ii > Ad[N], da[N];

vector < int > tp, c;
bool cmp(int x, int y) {
	return d[x][0][0] < d[y][0][0];
}

void maxi(long long &A, const long long B) {
	if(B > A) A = B;
}

long long dp[N][6][(1<<6) + 5];

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if ( fopen("voi19_workout.inp", "r") ){
        freopen("voi19_workout.inp", "r", stdin);
        freopen("voi19_workout.out", "w", stdout);
    }

	cin >> n >> m >> k;
	for(int i=1;i<=m;++i) {
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
		adj[ed[i].u].pb({ed[i].v, ed[i].w});
		adj[ed[i].v].pb({ed[i].u, ed[i].w});
	}

	cin >> st[0][0] >> st[0][1];

	for(int i=1;i<k;++i) {
		cin >> b[i] >> st[i][0] >> st[i][1];
	}

	for(int i=0;i<k;++i) {
		dic(i, 0);
		dic(i, 1);
	}

	for(int j=1;j<=m;++j) {
		int u = ed[j].u;
		int v = ed[j].v;
		int w = ed[j].w;
		if(d[u][0][0] + w + d[v][0][1] == d[st[0][1]][0][0]) {
			Ad[u].pb({v, w});
		}
		if(d[u][0][1] + w + d[v][0][0] == d[st[0][1]][0][0]) {
			Ad[v].pb({u, w});
		}
	}

	/// kho tinh
	for(int i=1;i<k;++i) if(!b[i]) {
		for(int j=1;j<=m;++j) {
			int u = ed[j].u;
			int v = ed[j].v;
			int w = ed[j].w;
			if(d[u][i][0] + w + d[v][i][1] == d[st[i][1]][i][0]
		    && d[u][0][0] + w + d[v][0][1] == d[st[0][1]][0][0]
		    && d[u][i][0] == d[u][0][0]) da[u].pb({v, w});

			if(d[u][i][1] + w + d[v][i][0] == d[st[i][1]][i][0]
			&& d[u][0][1] + w + d[v][0][0] == d[st[0][1]][0][0]
			&& d[v][i][0] == d[v][0][0]) da[v].pb({u, w});
		}
	}

	for(int i=1;i<=n;++i) tp.pb(i);
	sort(tp.begin(), tp.end(), cmp);

	memset(dp, -0x3f, sizeof dp);

	for(int i=0;i<k;++i) if(b[i]) c.pb(i); /// de tinh

	int nn = c.size();

	dp[st[0][0]][nn][0] = 0;
	ll res = -Inf;
	for(int i : tp) {
		for(int bm=0;bm<(1<<nn);++bm) {
			for(int j=0;j<nn;++j) if(!bit(bm, j)) {
				int cur = c[j];
				maxi(res, dp[i][j][bm]);

				///dong lai (j -> nn)
				maxi(dp[i][nn][bm|(1<<j)], dp[i][j][bm]);

				///di tiep cung 1 thang de tinh
				for(ii x : Ad[i]) if(d[i][cur][0] + x.se + d[x.fi][cur][1] == d[st[cur][1]][cur][0]) {
					maxi(dp[x.fi][j][bm], dp[i][j][bm] + x.se);
				}
			}

			maxi(res, dp[i][nn][bm]);

			///di tiep cung 1 thang kho tinh
			for(ii x : da[i]) maxi(dp[x.fi][nn][bm], dp[i][nn][bm] + x.se);

			///di tiep 1 minh
			for(ii x : Ad[i]) maxi(dp[x.fi][nn][bm], dp[i][nn][bm]);

			///di tiep cung 1 thang de tinh
			for(ii x : Ad[i])
			for(int j=0;j<nn;++j) if(!bit(bm, j)) {
				int cur = c[j];
				if(d[i][cur][0] + x.se + d[x.fi][cur][1] == d[st[cur][1]][cur][0]) {
					maxi(dp[x.fi][j][bm], dp[i][nn][bm] + x.se);
				}
			}
		}
	}
	cout << res;
}
