#include <bits/stdc++.h>
#define maxn 1000005
#define maxm 10000005
#define maxc 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<long long, long long>
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i--)
#define Task "UPGRANET"
#define fast ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define stop1 {cout << "-1\n"; return;}
#define stop2 {cout << "0\n"; return;}
#define stop3 {cout << "yes\n"; exit(0);}
#define skip1 {cout << "Yes\n"; continue;}
#define skip2 {cout << "No\n"; continue;}
#define ll long long

using namespace std;

ll n, m, root[maxn], h[maxn], res;
pii  par[maxn][20];
bool dd[maxn];
vector<pair<ll, ll> > ke[maxn];
struct canh
{
    ll u, v, w;
}ed[maxn];

void setup()
{
    cin >> n >> m;
    fort(i, 1, m)
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
}

bool cmp(canh p, canh q)
{
    return p.w > q.w;
}

ll getroot(ll u)
{
    if(root[u] == 0) return u;
    return root[u] = getroot(root[u]);
}

void make_tree()
{
    sort(ed+1, ed+m+1, cmp);
    fort(i, 1, m)
    {
        ll p = getroot(ed[i].u);
        ll q = getroot(ed[i].v);
        if(p == q) continue;
        root[p] = q;
        dd[i] = 1;
        ke[ed[i].u].pb(mp(ed[i].v, ed[i].w));
        ke[ed[i].v].pb(mp(ed[i].u, ed[i].w));
    }
}

void dfs(ll u, ll tr)
{
    fort(i, 0, int(ke[u].size()) - 1)
    {
        ll v = ke[u][i].F;
        if(v == tr) continue;
        h[v] = h[u] + 1;
        par[v][0] = mp(u,ke[u][i].S);
        fort(j, 1, 18)
        {
            par[v][j].F = par[par[v][j-1].F][j-1].F;
            par[v][j].S = min(par[par[v][j-1].F][j-1].S, par[v][j-1].S);
        }
        dfs(v, u);
    }
}

pii lca(ll u, ll v)
{
    pii p;
    p.S = 1ll* maxc * maxc;
    if( h[u] > h[v])
        swap(u, v);
    ll diff = h[v] - h[u];
    ford(i, 18, 0)
        if((diff >> i) & 1)
        {
            p.S = min(p.S, par[v][i].S);
            v = par[v][i].F;

        }
    if(v == u) return mp(u, p.S);
    ford(i, 18, 0)
        if(par[u][i].F != par[v][i].F)
        {
            p.S = min(p.S, min(par[v][i].S, par[u][i].S));
            v = par[v][i].F;
            u = par[u][i].F;
        }
    return mp(par[u][0].F, min(p.S, min(par[u][0].S, par[v][0].S)));
}

void work()
{
    make_tree();
    h[1] = 1;
    dfs(1, 0);
    fort(i, 1, m)
        if(!dd[i])
        {
            pii l = lca(ed[i].u, ed[i].v);
            res += max(0ll, l.S - ed[i].w);
        }
    cout << res;
}


int main()
{
    fast
    setup();
    work();
    return 0;
}
