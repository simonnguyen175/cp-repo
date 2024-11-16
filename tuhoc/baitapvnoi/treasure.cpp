#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const int base = 96 * 1000;
const ll oo = 1e12;

int n, a[N];

namespace sub2{
    ll sa = 0, sb = 0;
    map<ll, int> d;

    void gen1(int id, ll sa, ll sb){
        if ( id == n/2 ){
            if ( d.find(sa-sb) == d.end() )
                d[sa-sb] = s1-sa-sb;
            else d[sa-sb] = min(d[sa-sb], s1-sa-sb);
        }
        else{
            gen1(id + 1, sa, sb);
            gen1(id + 1, sa + a[i+1], sb);
            gen1(id + 1, sa, sb + a[i+1]);
        }
    }

    void solve(){
        for (int i = 1; i <= n/2; i ++) s1 += a[i];
        for (int i = n/2 + 1; i <= n; i ++) s2 += a[i];

    }
}

namespace sub4{
    ll f[100][2*base+5];

    void solve(){
        for (int i = 0; i <= n; i ++)
            for (int j = -base; j <= base; j ++)
                f[i][j+base] = oo;
        f[0][base] = 0;

        for (int i = 0; i < n; i ++)
            for (int j = -base; j <= base; j ++){
                if ( f[i][j+base] == oo ) continue;
                f[i+1][j+base] = min(f[i+1][j+base], f[i][j+base] + a[i+1]);
                if ( j + a[i+1] <= base )
                    f[i+1][j + a[i+1] + base] = min(f[i+1][j + a[i+1] + base] , f[i][j+base]);
                if ( j - a[i+1] >= -base )
                    f[i+1][j - a[i+1] + base] = min(f[i+1][j - a[i+1] + base], f[i][j+base]);
            }

        cout << f[n][base] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> n ){
        for (int i = 1; i <= n; i ++)
            cin >> a[i];

        if ( n <= 24 ) sub2::solve();
        else sub4::solve();
    }

    return 0;
}
