#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e2 + 5;

int n, w, h;
pi a[N];
vector<int> row[N];
int ans[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("map.inp", "r") ){
        freopen("map.inp", "r", stdin);
        freopen("map.out", "w", stdout);
    }

    cin >> n >> w >> h;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    a[n+1] = a[1];

    for (int i = 1; i <= n; i ++){
        if ( a[i].fi == a[i+1].fi ){
            int l = min(a[i].se, a[i+1].se) + 1;
            int r = max(a[i].se, a[i+1].se);
            for (int j = l; j <= r; j ++)
                row[j].pb(a[i].fi);
        }
    }

    for (int i = 1; i <= h; i ++){
        if ( row[i].size() ){
            sort(row[i].begin(), row[i].end());
//            cout << i << " : ";
//            for (int x : row[i]) cout << x << ' '; cout << '\n';
            for (int k = 0; k < row[i].size() - 1; k += 2)
                for (int j = row[i][k] + 1; j <= row[i][k+1]; j ++)
                    ans[i][j] = 1;
        }
    }

    for (int i = h; i >= 1; i --){
        for (int j = 1; j <= w; j ++)
            cout << ( ans[i][j] ? '#' : '.' );
        cout << '\n';
    }

    return 0;
}
