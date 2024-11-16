#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;
const int M = 1510;

int n, m;
ll cnt[M][M], id1[M][M], id2[M][M], c[N], d[N];
vector<int> cont[N];

void addCnt(int x, int y, int u, int v){
    cnt[x][y] ++, cnt[x][v+1] --, cnt[u+1][y] --, cnt[u+1][v+1] ++;
}

void addIdx(int x, int y, int u, int v, int w){
    id1[x][y] += w, id1[x][v+1] -= w, id1[u+1][y] -= w, id1[u+1][v+1] += w;
    id2[x][y] += 1LL*w*w, id2[x][v+1] -= 1LL*w*w, id2[u+1][y] -= 1LL*w*w, id2[u+1][v+1] += 1LL*w*w;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i <= m+5; i ++)
    for (int j = 0; j <= m+5; j ++)
        cnt[i][j] = id1[i][j] = id2[i][j] = 0;

    for (int i = 1; i <= n; i ++)
        cont[i].clear(), c[i] = 0;

    for (int i = 1; i <= n; i ++){
        int x, y, u, v;
        cin >> x >> u >> y >> v;
        addCnt(x, y, u, v);
        addIdx(x, y, u, v, i);
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= m; j ++){
        cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
        id1[i][j] += id1[i-1][j] + id1[i][j-1] - id1[i-1][j-1];
        id2[i][j] += id2[i-1][j] + id2[i][j-1] - id2[i-1][j-1];
    }

//    for (int i = 1; i <= m; i ++){
//        for (int j = 1; j <= m; j ++)
//            cout << cnt[i][j];
//        cout << '\n';
//    }
//    cout << '\n';
//    for (int i = 1; i <= m; i ++){
//        for (int j = 1; j <= m; j ++)
//            cout << id1[i][j] << ' ';
//        cout << '\n';
//    }
//    cout << '\n';
//    for (int i = 1; i <= m; i ++){
//        for (int j = 1; j <= m; j ++)
//            cout << id2[i][j] << ' ';
//        cout << '\n';
//    }

    ll sl = 0;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= m; j ++){
        if ( cnt[i][j] ) sl ++;
        if ( cnt[i][j] == 1 ) c[id1[i][j]] ++;
        if ( cnt[i][j] == 2 ){
            ll sub = sqrt(2*id2[i][j] - id1[i][j]*id1[i][j]);
            ll sum = id1[i][j];
            ll a = ( sum - sub ) / 2;
            ll b = sum - a;
//            cout << a << ' ' << b << '\n';
            cont[a].pb(b);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        for (int j : cont[i]){
            d[j] ++;
            ans = max(ans, c[i]+c[j]+d[j]);
        }
        for (int j : cont[i]) d[j] --;
    }

    pi mx = {0, 0};
    for (int i = 1; i <= n; i ++)
        if ( c[i] > mx.fi ) mx ={c[i], mx.fi};
        else if ( c[i] > mx.se ) mx.se = c[i];
    ans = max(ans, mx.fi+mx.se);

    cout << sl - ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("in.inp", "r") ){
        freopen("in.inp", "r", stdin);
        freopen("out.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
