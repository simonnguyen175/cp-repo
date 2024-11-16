#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, k;
ll x, s[N];
int a[N];
map<int, int> d;

namespace sub1{
    void solve(){
        int cnt = 0;
        for (int i = 1; i <= n; i ++){
            cerr << i << '\n';
            for (int j = 1; j <= n; j ++)
                d[j] = 0;

            a[1] = i;
            a[2] = s[1] - a[1];
            d[a[1]] = d[a[2]] = 1;

            for (int i = 3; i <= n; i ++){
                a[i] = a[i-2] + s[i-1] - s[i-2];
                d[a[i]] = 1;
            }

            bool ck = 1;
            for (int j = 1; j <= n; j ++)
                ck &= d[j];

            cnt += ck;

            if ( cnt == x ){
                for (int i = 1; i <= n; i ++) cout << a[i] << ' ';
                cout << '\n';
                return;
            }
        }

        cout << -1 << '\n';
    }
}

bitset<2*N+5> b[2], c[4];

namespace sub2{
    int a[N];

    void solve(){
        for (int i = 0; i <= 2; i ++) c[i].reset();
        b[0].reset(); b[1].reset();

        int d = 0;
        b[0][n] = 1;
        for (int i = 3; i <= n; i += 2){
            d += s[i-1] - s[i-2];
            if ( d >= n ){
                cout << -1 << '\n';
                return;
            }
            b[0][d+n] = 1;
        }

        b[1][n] = 1;
        d = 0;
        for (int i = 4; i <= n; i += 2){
            d += s[i-1] - s[i-2];
            if ( d >= n ){
                cout << -1 << '\n';
                return;
            }
            b[1][d+n] = 1;
        }

//        for (int i = n-1; i <= 2*n+1; i ++)
//            cout << b[0][i] << ' ';
//        cout << '\n';
//        for (int i = n-1; i <= 2*n+1; i ++)
//            cout << b[1][i] << ' ';
//        cout << '\n';
//
//        cout << "bitset time\n";

        int cnt = 0;
        for (int i = 1; i <= n; i ++){
            c[0] = b[0] << i;
            c[1] = b[1] << (s[1]-i);

//            cout << i << " : \n";
//            for (int j = n; j <= 2*n+1; j ++)
//                cout << c[0][j] << ' ';
//            cout << '\n';
//            for (int j = n; j <= 2*n+1; j ++)
//                cout << c[1][j] << ' ';
//            cout << '\n';
            c[2] = c[0] | c[1];
//            for (int j = n; j <= 2*n+1; j ++)
//                cout << c[2][j] << ' ';
//            cout << '\n';
//            for (int j = n; j <= 2*n+1; j ++)
//                cout << c[3][j] << ' ';
//            cout << '\n';

            if ( c[2] == c[3] ) cnt ++;
            if ( cnt == x ){
                a[1] = i, a[2] = s[1] - i;
                for (int j = 3; j <= n; j ++)
                    a[j] = a[j-2] + s[j-1] - s[j-2];
                for (int j = 1; j <= n; j ++)
                    cout << a[j] << ' ';
                cout << '\n';
                return;
            }
        }

        cout << -1 << '\n';
    }
}

void solve(){
    cin >> n >> k >> x;
    for (int i = 1; i <= n-k+1; i ++)
        cin >> s[i];

    for (int i = 1; i <= n; i ++)
        c[3][n+i] = 1;

//    if ( k == 2 && n <= 5000 ) sub1::solve();
//    else
        sub2::solve();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("compress.inp", "r", stdin);
    freopen("compress.out", "w", stdout);

    int test;
    cin >> test;
    while ( test-- )
        solve();

    return 0;
}
