#include<bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int N = 1e5 + 5;

int n, x, y, z;
int a[N], b[N];

namespace sub1{
    int id[N], c[N];

    void solve(){
        int ans = oo;

        for (int i = 1; i <= n; i ++) id[i] = i;

        do{
            for (int i = 1; i <= n; i ++) c[i] = a[i];

            int tmp = 0;
            for (int i = 1; i <= n; i ++){
                if ( id[i] == i ) continue;
                else c[i] --, c[id[i]] ++, tmp += z * abs(id[i] - i);
            }

            for (int i = 1; i <= n; i ++) cout << id[i] << ' '; cout << '\n';

            bool ck = 1;
            for (int i = 1; i <= n; i ++) ck &= ( c[i] >= 0 );

            if ( ck ){
                for (int i = 1; i <= n; i ++)
                    if ( b[i] < c[i] ) tmp += x;
                    else tmp += y;
                ans = min(ans, tmp);
            }
            else continue;
        }while ( next_permutation(id+1, id+1+n));

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("2.inp", "r") ){
        freopen("2.inp", "r", stdin);
        freopen("2.out", "w", stdout);
    }

    cin >> n >> x >> y >> z;

    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    if ( n <= 10 ) sub1::solve();

    return 0;
}
