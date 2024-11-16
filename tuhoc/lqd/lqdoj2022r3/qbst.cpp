#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

int n, ans;
int c[N], w[N], sw[N], mn[N][20];

int minn(int a, int b){
    if ( c[a] <= c[b] ) return a;
    else return b;
}

int get(int l, int r){
    int k = __lg(r-l+1);
    return minn(mn[l][k], mn[r-(1<<k)+1][k]);
}

void dfs(int l, int r){
    if ( l > r ) return;
    int mid = get(l, r);
    ans = max(ans, c[mid] + sw[r] - sw[l-1]);
    dfs(l, mid-1);
    dfs(mid+1, r);
}

void trace(int l, int r){
    if ( l > r ) return;

    int lim = ans - sw[r] + sw[l-1];

    int lo = l, hi = r, pos = r+1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( c[get(mid, r)] > lim ) pos = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    pos --;
    cout << pos << ' ';

    trace(l, pos-1);
    trace(pos+1, r);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("qbst.inp", "r") ){
        freopen("qbst.inp", "r", stdin);
        freopen("qbst.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> c[i];
    for (int i = 1; i <= n; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++){
        c[i] -= w[i];
        mn[i][0] = i;
        sw[i] = sw[i-1] + w[i];
    }

    for (int j = 1; j <= 17; j ++)
    for (int i = 1; i <= n; i ++)
        mn[i][j] = minn(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);

    dfs(1, n);
    cout << ans << '\n';
    trace(1, n);

    return 0;
}
