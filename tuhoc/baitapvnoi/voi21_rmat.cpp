#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int m, n, ans = 1;
vector<vector<ll>> a;
vector<ll> row, col;
int f[N][45], dp[N];

int get(vector<int> &tmp){
    if ( !tmp.size() ) return 0;

//    for (auto it : tmp) cout << it << ' '; cout << " : ";

    for (int i = 0; i <= tmp.size()+1; i ++)
    for (int j = 0; j <= 40; j ++)
        f[i][j] = -1;

    for (int i = 1; i <= tmp.size(); i ++)
        f[i][tmp[i-1]] = i;

    for (int j = 1; j <= 40; j ++)
    for (int i = 1; i <= tmp.size(); i ++)
        if ( f[i][j-1] != -1 )
            f[i][j] = f[f[i][j-1]+1][j-1];

    for (int i = 1; i <= tmp.size(); i ++) dp[i] = tmp.size() + 1;
    dp[0] = 0;
    for (int i = 0; i <= tmp.size(); i ++)
    for (int j = 0; j <= 40; j ++)
        if ( f[i+1][j] != -1 ){
            dp[f[i+1][j]] = min(dp[f[i+1][j]], dp[i] + 1);
        }

//    cout << dp[tmp.size()] << '\n';

    return dp[tmp.size()];
}

void solve(vector<ll> a){
//    cout << "here \n";
//    for (int i = 1; i < a.size(); i ++) cout << a[i] << ' '; cout << '\n';

    int res = 0, cnt = 0, cnt0 = 0, cur = 0;

    vector<int> tmp;

    for (int i = 1; i < a.size(); i ++){
        if ( a[i] == 0 ) { cur = 0; cnt0 ++; continue; }
        else{
            if ( cnt0 ) res ++, cnt0 = 0;
            cnt = 0;
            while ( a[i] % 2 == 0 ) { a[i] /= 2; cnt ++; }
            if ( a[i] != cur ){
                res += get(tmp);
                tmp.clear();
                tmp.pb(cnt);
                cur = a[i];
            }
            else tmp.pb(cnt);
        }
    }

    if ( cnt0 ) res ++;

    res += get(tmp);

//    cout << res << '\n';

    ans *= res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi21_rmat.inp", "r") ){
        freopen("voi21_rmat.inp", "r", stdin);
        freopen("voi21_rmat.out", "w", stdout);
    }

    cin >> m >> n;
    a.resize(m+1);
    for (int i = 1; i <= m; i ++) a.resize(n+1);

    row.resize(m+1);
    col.resize(n+1);

    for (int i = 1; i <= m; i ++)
    for (int j = 1, x; j <= n; j ++){
        cin >> x;
        row[i] += x, col[j] += x;
    }

    solve(row);
    solve(col);

    cout << ans << '\n';

    return 0;
}
