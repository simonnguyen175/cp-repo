#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const long long oo = 1e15;

int n, m;
int c[N], p[N];
bool ok[N][N], d[N], dd[N], a[N], b[N];
long long ans;

namespace sub2{
    void gen(int id){
        for (int i = 0; i <= 1; i ++){
            dd[id] = i;
            if ( id == m ){
                for (int j = 1; j <= n; j ++) d[j] = 0;
                for (int j = 1; j <= n; j ++){
                    bool ck = 1;
                    for (int k = 1; k <= m; k ++) if ( ok[j][k] && !dd[k] ){
                        ck = 0;
                        break;
                    }
                    if ( ck ) d[j] = 1;
                }

                long long res = 0;
                for (int j = 1; j <= n; j ++) if ( d[j] )
                    res += p[j];

                for (int j = 1; j <= m; j ++) if ( dd[j] ){
                    res -= c[j];
                }

                if ( ans < res ){
                    ans = res;

                    for (int j = 1; j <= n; j ++) a[j] = d[j];
                    for (int j = 1; j <= m; j ++) b[j] = dd[j];
                }
            }
            else gen(id + 1);
        }
    }

    void solve(){
        ans = -oo;
        gen(1);
        cout << ans << '\n';
        for (int i = 1; i <= n; i ++) if ( a[i] ) cout << i << ' '; cout << '\n';
        for (int i = 1; i <= n; i ++) if ( b[i] ) cout << i << ' ';
    }
}

namespace sub1{
    void gen(int id){
        for (int i = 0; i <= 1; i ++){
            d[id] = i;
            if ( id == n ){
                for (int j = 1; j <= m; j ++) dd[j] = 0;

                for (int j = 1; j <= n; j ++) if ( d[j] ){
                    for (int k = 1; k <= m; k ++) if ( ok[j][k] )
                        dd[k] = 1;
                }

                long long res = 0;
                for (int j = 1; j <= n; j ++) if ( d[j] )
                    res += p[j];

                for (int j = 1; j <= m; j ++) if ( dd[j] )
                    res -= c[j];

                if ( ans < res ){
                    ans = res;
                    for (int j = 1; j <= n; j ++) a[j] = d[j];
                    for (int j = 1; j <= m; j ++) b[j] = dd[j];
                }
            }
            else gen(id + 1);
        }
    }

    void solve(){
        ans = -oo;
        gen(1);
        cout << ans << '\n';
        for (int i = 1; i <= n; i ++) if ( a[i] ) cout << i << ' '; cout << '\n';
        for (int i = 1; i <= m; i ++) if ( b[i] ) cout << i << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    for (int i = 1; i <= m; i ++)
        cin >> c[i];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> ok[i][j];

    if ( n <= 20 ) sub1::solve();
    else if ( m <= 20 ) sub2::solve();

    return 0;
}
