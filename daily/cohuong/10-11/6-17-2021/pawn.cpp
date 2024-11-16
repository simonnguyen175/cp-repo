#include<bits/stdc++.h>
#define simon "pawn"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e2 + 5;

struct opt{
    int sum = -1, start = 0;
    string way = "";
};

int n, m, k;
int a[N][N];
opt dp[N][N][20];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void init(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++){
        string s; cin >> s;
        for (int j = 1; j <= m; j ++)
            a[i][j] = (int) s[j-1] - '0';
    }
    k ++;
}

void anal(int i, int j, int e, int x){
    int su = dp[i][j][e].sum, stu = dp[i][j][e].start;
    string wu = dp[i][j][e].way, nw = wu + ( x == 1 ? 'R' : 'L' );
    //cout << i << ' ' << j << ' ' << e << ' ' << su << ' ' << stu << ' ' << wu << " - > ";

    if ( j + x >= 1 && j + x <= m ){
            if ( dp[i-1][j+x][(e + a[i-1][j+x])%k].sum < su + a[i-1][j+x] ){
                dp[i-1][j+x][(e + a[i-1][j+x])%k].sum = su + a[i-1][j+x];
                dp[i-1][j+x][(e + a[i-1][j+x])%k].start = stu;
                dp[i-1][j+x][(e + a[i-1][j+x])%k].way = nw;
            }

            if ( dp[i-1][j+x][(e + a[i-1][j+x])%k].sum == su + a[i-1][j+x]){
                if ( dp[i-1][j+x][(e + a[i-1][j+x])%k].start > stu ){
                    dp[i-1][j+x][(e + a[i-1][j+x])%k].start = stu;
                    dp[i-1][j+x][(e + a[i-1][j+x])%k].way = nw;
                }
                if ( dp[i-1][j+x][(e + a[i-1][j+x])%k].start == stu )
                    if ( dp[i-1][j+x][(e + a[i-1][j+x])%k].way > nw )
                        dp[i-1][j+x][(e + a[i-1][j+x])%k].way = nw;
            }

            //cout << i - 1 << ' ' << j + x << ' ' << (e + a[i-1][j+x])%k << ' ' << dp[i-1][j+x][(e + a[i-1][j+x])%k].sum << ' ' << dp[i-1][j+x][(e + a[i-1][j+x])%k].start << ' ' <<  dp[i-1][j+x][(e + a[i-1][j+x])%k].way << '\n';
        }
    //else cout << '\n';

}

void solve(){
    for (int i = 1; i <= m; i ++){
        dp[n][i][a[n][i] % k].sum = a[n][i];
        dp[n][i][a[n][i] % k].start = i;
        dp[n][i][a[n][i] % k].way = "";
    }

    for (int i = n; i >= 2; i --)
    for (int j = 1; j <= m; j ++)
    for (int e = 0; e < k; e ++){
        if ( dp[i][j][e].sum == -1 ) continue;
        // len tren sang trai
        anal(i, j, e, -1);
        // len tren sang phai
        anal(i, j, e, 1);
    }

    opt ans;
    for (int i = 1; i <= m; i ++){
        if ( dp[1][i][0].sum == 0 ) continue;
        if ( ans.sum < dp[1][i][0].sum ){
            ans.sum = dp[1][i][0].sum;
            ans.start = dp[1][i][0].start;
            ans.way = dp[1][i][0].way;
        }

        if ( ans.sum == dp[1][i][0].sum ){
            if ( ans.start > dp[1][i][0].start ){
                ans.start = dp[1][i][0].start;
                ans.way = dp[1][i][0].way;
            }
            if ( ans.start == dp[1][i][0].start )
                if ( ans.way > dp[1][i][0].way ) ans.way = dp[1][i][0].way;
        }
    }

    /*
    int x = n, y = ans.start;
    int sum = a[x][y];
    cout << x << ' ' << y << ' ' << sum << '\n';
    for (int i = 0; i < ans.way.size(); i ++){
        if ( ans.way[i] == 'L' ){
            x --; y --;
            sum += a[x][y];
            cout << x << ' ' << y << ' ' << sum << '\n';
        }
        else{
            x --; y ++;
            sum += a[x][y];
            cout << x << ' ' << y << ' ' << sum << '\n';
        }
    }
    */

    if ( ans.sum == 0 ) cout << -1;
        else
    cout << ans.sum << '\n' << ans.start << '\n' << ans.way << '\n';
}

int main(){
    file();
    init();
    solve();
    return 0;
}
