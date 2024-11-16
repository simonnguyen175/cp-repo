#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n;
int a[N];
map<int, int> id;
int bit[2*N][4], f[N][4];

int get(int u, int t){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res = max(res, bit[u][t]);
    return res;
}

void update(int u, int t, int v){
    for (; u <= 2*n; u += u&-u)
        bit[u][t] = max(bit[u][t], v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("lis.inp", "r") ){
        freopen("lis.inp", "r", stdin);
        freopen("lis.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    vector<int> cont;
    for (int i = 1; i <= n; i ++)
        cont.pb(a[i]), cont.pb(-a[i]);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        f[i][1] = get(id[a[i]]-1, 1) + 1;
        f[i][2] = max(get(id[-a[i]]-1, 1), get(id[-a[i]]-1, 2)) + 1;
        f[i][3] = max(get(id[a[i]]-1, 2), get(id[a[i]]-1, 3)) + 1;
        update(id[a[i]], 1, f[i][1]);
        update(id[-a[i]], 2, f[i][2]);
        update(id[a[i]], 3, f[i][3]);
        ans = max({ans, f[i][2], f[i][3], f[i][1]});
    }

    cout << ans;

    return 0;
}
