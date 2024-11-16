#include<bits/stdc++.h>
#define simon "game"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, t;
int a[N];
pair<int, int> sp[N][25];
int Log[25];

int get(int u, int v){
    int j = Log[v - u + 1];
    return max(sp[u][j].second, sp[v-(1<<j)+1][j].second) - min(sp[u][j].first, sp[v-(1<<j)+1][j].first);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    // make sparse table
    Log[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i/2] + 1;

    for (int i = 1; i <= n; i ++){
        sp[i][0].first = a[i];
        sp[i][0].second = a[i];
    }

    for (int j = 1; j <= Log[n]; j ++)
        for (int i = 1; i + ( 1 << j ) - 1<= n; i ++){
            sp[i][j].first = min(sp[i][j-1].first, sp[i+(1<<(j-1))][j-1].first);
            sp[i][j].second = max(sp[i][j-1].second, sp[i+(1<<(j-1))][j-1].second);
        }


    // solve
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int lo = 1, hi = i, j;
        while ( lo <= hi ){
            int mid = ( lo + hi ) / 2;
            if ( get(mid, i) <= t ){
                hi = mid - 1;
                j = mid;
            }
            else lo = mid + 1;
        }
        ans = max(ans, i - j + 1);
    }

    cout << ans;

    return 0;
}
