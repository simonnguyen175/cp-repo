#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N], b[N], f[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> n ){
        for (int i = 1; i <= n; i ++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i ++) cin >> b[i];

        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
            f[i][j] = 0;

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        f[i][j] = max({f[i][j-1], f[i-1][j], f[i-1][j-1] + ( a[i] == b[j] )});

        cout << f[n][m] << '\n';
    }

//    vector<int> ans;
//    while ( n && m ){
//        if ( f[n][m] == f[n][m-1] ) m --;
//        else if ( f[n][m] == f[n-1][m] ) n --;
//        else if ( f[n][m] == f[n-1][m-1] + ( a[n] == b[m] ) ){
//            if ( a[n] == b[m] ) ans.pb(a[n]);
//            n --, m --;
//        }
//    }
//
//    reverse(ans.begin(), ans.end());
//    for (auto x : ans) cout << x << ' ';

    return 0;
}
