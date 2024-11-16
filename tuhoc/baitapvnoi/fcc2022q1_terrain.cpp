#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, k, t;
int h[N];
pi a[N];
int bit[N][20];
vector<int> node[N];
vector<ll> cont1, cont2;
map<ll, int> id1, id2;

void fakeupdate(int x, int y){
    for (; x <= n; x += x&-x)
        node[x].pb(y);
}

void fakeget(int x, int y){
    for (; x >= 1; x -= x&-x)
        node[x].pb(y);
}

void update(int x, int yy, int val){
    for (; x <= n; x += x&-x)
        for (int y = lower_bound(node[x].begin(), node[x].end(), yy) - node[x].begin() + 1; y <= node[x].size(); y += y&-y)
            bit[x][y] = max(bit[x][y], val);
}

int get(int x, int yy){
    int res = 0;
    for (; x > 0; x -= x&-x){
        for (int y = upper_bound(node[x].begin(), node[x].end(), yy) - node[x].begin(); y > 0; y -= y&-y)
            res = max(res, bit[x][y]);
    }
    return res;
}

bool check(int D){
    cont1.clear();
    cont2.clear();

    for (int i = 1; i <= n; i ++){
        a[i].fi = 1LL*D*i - h[i];
        a[i].se = 1LL*D*i + h[i];
        cont1.pb(a[i].fi); cont2.pb(a[i].se);
    }

    sort(cont1.begin(), cont1.end());
    cont1.erase(unique(cont1.begin(), cont1.end()), cont1.end());
    for (int i = 0; i < cont1.size(); i ++)
        id1[cont1[i]] = i + 1;

    sort(cont2.begin(), cont2.end());
    cont2.erase(unique(cont2.begin(), cont2.end()), cont2.end());
    for (int i = 0; i < cont2.size(); i ++)
        id2[cont2[i]] = i + 1;

    for (int i = 1; i <= n; i ++) node[i].clear();

    for (int i = 1; i <= n; i ++){
        fakeget(id1[a[i].fi], id2[a[i].se]);
        fakeupdate(id1[a[i].fi], id2[a[i].se]);
    }

    for (int i = 1; i <= n; i ++){
        sort(node[i].begin(), node[i].end());
        node[i].erase(unique(node[i].begin(), node[i].end()), node[i].end());
    }

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= 20; j ++)
        bit[i][j] = 0;

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int tmp = get(id1[a[i].fi], id2[a[i].se]);
        tmp ++;
        ans = max(ans, tmp);
        update(id1[a[i].fi], id2[a[i].se], tmp);
    }

    return ( n - ans <= k );
}

void solve(){
    cin >> n >> k;

    for (int i = 1; i <= n; i ++)
        cin >> h[i];

    int lo = 0, hi = 1e9, res;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> t;

    while ( t -- ) solve();

    return 0;
}
