#include<bits/stdc++.h>
#define st string
#define vs deque<string>
#define pb push_back
using namespace std;

const int N = 1e3+5;
int n, m, i, j, k, cnt, ans[N];
char a[N][N]; st f[N][N];
vs s[N]; map<vs, int> dem, calc;
bool vis[N][N];

bool in( int u, int v )
{
    return ( u>0 && u<=n && v>0 && u<=m && a[u][v]=='#' );
}

bool check( int u, int v )
{
    bool ok = true;
    ok = ok && ( in(u, v) && in(u, v+1) && in(u, v+2) && in(u, v+3) && in(u, v+4) );
    //cout << u << ' ' << ok << '\n';

    u++;
    ok = ok && ( in(u, v) && in(u, v+4) );
   // cout << u << ' ' << ok << '\n';

    u++;
    ok = ok && ( in(u, v) && in(u, v+4) );
    //cout << u << ' ' << ok << '\n';

    u++;
    ok = ok && ( in(u, v) && in(u, v+4) );
    //cout << u << ' ' << ok << '\n';

    u++;
    ok = ok && ( in(u, v) && in(u, v+1) && in(u, v+2) && in(u, v+3) && in(u, v+4) );
   // cout << u << ' ' << ok << '\n';
    return ok;
}

st nen( int u, int v )
{
    st res = "";
    u++; v++;
    res += a[u][v];
    res += a[u][v+1];
    res += a[u][v+2];
    //cout << res << ' ' << a[u][v] << ' ' << a[u][v+1] << ' ' << a[u][v+2] << '\n';

    u++;
    res += a[u][v];
    res += a[u][v+1];
    res += a[u][v+2];
    //cout << res << ' ' << a[u][v] << ' ' << a[u][v+1] << ' ' << a[u][v+2] << '\n';

    u++;
    res += a[u][v];
    res += a[u][v+1];
    res += a[u][v+2];
    //cout << res << ' ' << a[u][v] << ' ' << a[u][v+1] << ' ' << a[u][v+2] << '\n';

    return res;
}

st xoay( st x )
{
    st res = "";
    int pos = 2;

    res += x[pos];
    res += x[pos+3];
    res += x[pos+6];
    pos--;

    res += x[pos];
    res += x[pos+3];
    res += x[pos+6];
    pos--;

    res += x[pos];
    res += x[pos+3];
    res += x[pos+6];

    return res;
}

void dfs( int u, int v, int need )
{
    if( need )
    {
        s[cnt].pb( xoay(f[u][v]) );
        vis[u][v] = true;

        if( f[u+4][v]!="0" ) dfs(u+4, v, need);
    }
    else
    {
        s[cnt].pb( f[u][v] );
        vis[u][v] = true;

        if( f[u][v+4]!="0" ) dfs(u, v+4, need);
    }
}

void Up( st &x )
{
    swap(x[0], x[6]);
    swap(x[1], x[7]);
    swap(x[2], x[8]);
}

void Left( st &x )
{
    swap(x[0], x[2]);
    swap(x[3], x[5]);
    swap(x[6], x[8]);
}

void up( vs &x )
{
    int len = x.size();
    for(int t=0; t<len; t++)
        Up( x[t] );
}

void left( vs &x )
{
    int len = x.size();
    for(int t=0; t<len; t++)
        Left( x[t] );
}

int add( vs x )
{
    int res = 0;
    if( x.size()==1 )
    {
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        up( x );
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        left( x );
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        up( x );
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }
        return res;
    }

    int len = x.size();

    for(int t=0; t<len; t++)
    {
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        x.pb(x[0]);
        x.pop_front();
    }

    up( x );
    for(int t=0; t<len; t++)
    {
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        x.pb(x[0]);
        x.pop_front();
    }

    left( x );
    for(int t=0; t<len; t++)
    {
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        x.pb(x[0]);
        x.pop_front();
    }

    up( x );
    for(int t=0; t<len; t++)
    {
        if( calc[x]==0 )
        {
            res += dem[x];
            calc[x]=1;
        }

        x.pb(x[0]);
        x.pop_front();
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin >> a[i][j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            f[i][j] = "0";


    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if( a[i][j]=='#' && check(i, j) )
                f[i][j] = nen(i, j);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if( f[i][j]!="0" && !vis[i][j] )
            {
                cnt++;
                dfs(i, j, 1);
                if( s[cnt].size()==1 )
                {
                    s[cnt].pop_back();
                    dfs(i, j, 0);
                }
                dem[ s[cnt] ]++;
            }

    for(i=1; i<=cnt; i++)
        if( calc[s[i]]==0 )
        {
            k++;
            ans[k] = add( s[i] );
            calc[s[i]] = 1;
        }

    cout << k << '\n';
    sort(ans+1, ans+k+1);

    for(i=1; i<=k; i++) cout << ans[i] << ' ';
    return 0;
}
