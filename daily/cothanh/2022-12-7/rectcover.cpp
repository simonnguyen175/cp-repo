#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3 + 5;

int n, s;
pi a[N];
int mxy[N][N], dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("rectcover.in", "r") ){
        freopen("rectcover.in", "r", stdin);
        freopen("rectcover.out", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + 1 + n, [&](pi b, pi c){
        if ( b.x == c.x ) return b.y > c.y;
        else return b.x < c.x;
    });

    for (int i = 1; i <= n; i ++){
        mxy[i][i] = a[i].y;
        for (int j = i+1; j <= n; j ++)
            mxy[i][j] = max(mxy[i][j-1], a[j].y);
    }

//    for (int i = 1; i <= n; i ++)
//        cout << a[i].x << ' ' << a[i].y << '\n';

    for (int i = 0; i <= n+1; i ++)
    for (int j = 0; j <= n+1; j ++)
        dp[i][j] = n+1;

    for (int i = 1; i <= n; i ++)
        dp[i][i] = 1;

    for (int len = 2; len <= n; len ++){
//        cout << "length " << len << " : \n";
        for (int i = 1, j; i + len - 1 <= n; i ++){
            j = i + len - 1;
//            cout << i << ' ' << j << " : \n";
            for (int k = i; k < j; k ++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
//            cout << "first opt " << dp[i][j] << '\n';

            if ( a[j].x-a[i].x == 0 ) { dp[i][j] = 1; continue; }

            int limy = s/(a[j].x-a[i].x);
//            cout << a[j].x << ' ' << a[i].x << ' ' << limy << '\n';
            if ( !limy || a[i].y > limy || a[j].y > limy ) continue;

            int lo = i, hi = j, mid, ii;
            while ( lo <= hi ){
                mid = lo + hi >> 1;
                if ( mxy[i][mid] <= limy ) ii = mid, lo = mid + 1;
                else hi = mid - 1;
            }

            if ( ii == j ){
//                cout << "second opt " << 1 << '\n';
                dp[i][j] = 1;
                continue;
            }

            lo = i, hi = j;
            int jj;
            while ( lo <= hi ){
                mid = lo + hi >> 1;
                if ( mxy[mid][j] <= limy ) jj = mid, hi = mid - 1;
                else lo = mid + 1;
            }

            dp[i][j] = min(dp[i][j], dp[ii+1][jj-1] + 1);
//            cout << "second opt " << dp[i][j] << '\n';
        }
    }

    cout << dp[1][n];

    return 0;
}
