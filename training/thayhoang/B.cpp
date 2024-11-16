#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n;
int a[N];
int cnt[2][N];
map<pi, int> d[2];
vector<pi> cont[N];

void solve(){
    for (int i = 0; i <= 1; i ++)
        cont[i].clear(), d[i].clear();
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 1; j ++)
        cnt[j][i] = 0;

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cnt[i & 1][a[i]] ++;

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 1; j ++)
        cont[j].pb({cnt[j][i], i});
    for (int j = 0; j <= 1; j ++)
        sort(cont[j].begin(), cont[j].end(), greater<pi>());

    for (int i = 1; i <= n; i ++){
        int j = i;
        while ( j + 2 <= n && a[i] == a[j+2] ) j ++;
        d[i&1][{a[i], a[i+1]}] += (j - i + 2) / 2;
        d[(i+1)&1][{a[i+1], a[i]}] += (j - i + 2) / 2;
        i = j;
    }

    int ans = n;
    for (int i = 1; i <= n; i ++){
        for (auto it : cont[0]) if ( it.se != i ){
            ans = min(ans, n - (cnt[1][i] + it.fi) + d[0][{i, it.se}]);
            if ( !d[0][{i, it.se}] ) break;
        }
        ans = min(ans, n - max(cnt[0][i], cnt[1][i]));
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
