#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e4 + 5;
const ll oo = 1e18;

int n, k;
int a[N];
ll f[N][N];

void ckmn(ll &a, ll b){
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

int dfs(int l, int r){
    if ( l == r ) { f[l][0] = 0, f[l][1] = a[l]; return l; }

    int mid = l;
    for (int i = l + 1; i <= r; i ++)
        if ( a[i] > a[mid] )
            mid = i;

    int lef = 0, rig = 0;
    if ( l < mid ) lef = dfs(l, mid - 1);
    if ( r > mid ) rig = dfs(mid + 1, r);

    f[mid][0] = 0;

    if ( !lef ){
        for (int i = 1; i <= min(k, r - mid); i ++)
            f[mid][i] = f[rig][i];
    }
    if ( !rig ){
        for (int i = 1; i <= min(k, mid - l); i ++)
            f[mid][i] = f[lef][i];
    }
    else{
        for (int i = 1; i <= min(k, r - l); i ++)
        for (int j = 0; j <= min(i, mid - l); j ++){
            ckmn(f[mid][i], f[lef][j] + f[rig][i-j]
                      + 1ll * a[mid] * j * (i - j));
        }
    }

    for (int i = k - 1; i >= 0; i --)
        ckmn(f[mid][i+1], f[mid][i] + 1ll * i * a[mid] + a[mid]);

    return mid;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
        f[i][j] = oo;

    cout << f[dfs(1, n)][k];

    return 0;
}
