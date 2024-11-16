#include<bits/stdc++.h>
using namespace std;

#define FuMeng "treegcd"

//#define int long long
typedef pair<int, int> II;
typedef pair<long long, long long> LL;
typedef pair<long long, int> LLI;
typedef pair<int, long long> ILL;
#define fs first
#define sc second

#define pb push_back
#define eb emplace_back
#define BIT(x, k) (((x) >> k) & 1)
#define ms(d, k) memset(d, k, sizeof d)

#define FOR(i, d, k) for(int i = d; i <= k; ++i)
#define FOD(i, d, k) for(int i = d; i >= k; --i)
#define FORLL(i, d, k) for(long long i = d; i <= k; ++i)
/// PM with Lo VE ///

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[105];

int LCM(int a, int b)
{
	return a / __gcd(a, b) * b;
}

vector<int> save[N];
int prime[N];
int val;
///--///
void Eratos()
{
	FOR(i, 2, N - 1)
	{
		if(!prime[i])
		{
			for(int j = i * i; j <= N - 1; j += i)
				if(prime[j] == 0)
				   prime[j] = i;
		}
	}
	FOR(i, 2, N - 1)
		if(prime[i] == 0)
		   prime[i] = i;

	FOR(i, 2, m)
	{
		val = i;
		while(val >= 2)
		{
			if(save[i].empty() == true || save[i].back() != prime[val])
				save[i].pb(prime[val]);

			val /= prime[val];
		}
	}
}

long long f[105][N], g[N];
long long res;
///--///
void Try(int id, int val1, int d, int val2)
{
	if(id >= save[val2].size())
	{
		if(d % 2)
		{
			(res += g[val1]) %= MOD;
		}
		else
			(res -= g[val1]) %= MOD;

		return;
	}

	FOR(i, 0, 1)
	{
        if (i)
        Try(id + 1 , LCM(val1, save[val2][id]), d + 1, val2);
        else Try(id + 1, val1, d, val2);
    }
}

void DFS(int u, int par)
{
	FOR(i, 2, m)
	f[u][i] = 1;

	for(auto it : adj[u])
		if(it != par) DFS(it, u);

	for(auto it : adj[u])
	{
		if(par != it)
		{
			FOR(i, 2, m)
			{
				g[i] = 0;
				val = i;
				while(val <= m)
				{
					(g[i] += f[it][val]) %= MOD;
					val += i;
				}
				res = 0;
				Try(0, 1, 0, i);
				(f[u][i] *= res) %= MOD;
			}
		}
	}
}

///--///
void Input()
{
	cin >> n >> m;
	FOR(i, 1, n - 1)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
}
///201205/// <3
void Solve()
{
	Eratos();

	DFS(1, 0);
	res = 0;

	FOR(i, 2, m)
	(res += (f[1][i])) %= MOD;
	cout << (res % MOD + MOD) % MOD;
}
//main()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    if(fopen(FuMeng".inp", "r"))
    {
        freopen(FuMeng".inp", "r", stdin);
        freopen(FuMeng".out", "w", stdout);
    }
	Input();
	Solve();
	cout << '\n';
	return 0;
}
