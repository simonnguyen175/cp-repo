#include<bits/stdc++.h>
#define simon "lcp"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 105;

int n, m;
int a[N][N], pos[N][N], f[N];

bool check(int a, int b){
    for (int i = 1; i <= m; i ++)
        if ( pos[a][i] >= pos[b][i] ) return false;
    return true;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        int x; cin >> x;
        a[i][j] = x;
        pos[x][i] = j;
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        f[i] = 1;
        for (int j = 1; j < i; j ++)
            if ( check(a[1][j], a[1][i]) )
                f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }

    cout << ans;

    return 0;
}
