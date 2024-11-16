#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int n, x;
int a[N];

namespace Cand{
    int bit0[31];
    ll ans = 0;

    bool ok(int i){
        if ( (x&a[i]) == x ) return true;
        return false;
    }

    bool check(){
        for (int j = 0; j <= 30; j ++)
            if ( !BIT(x, j) && !bit0[j] ) return false;
        return true;
    }

    void add(int i){
        for (int j = 0; j <= 30; j ++)
            if ( !BIT(a[i], j) ) bit0[j] ++;
    }

    void sub(int i){
        for (int j = 0; j <= 30; j ++)
            if ( !BIT(a[i], j) ) bit0[j] --;
    }

    void solve(){
        int l = 1, r = 1;
        for (int i = 1; i <= n; i ++){
            if ( !ok(i) ){
                l = r = i + 1;
                for (int j = 0; j <= 30; j ++)
                    bit0[j] = 0;
                continue;
            }

            add(i);

            if  ( check() ){
                while ( check() && r <= i ) sub(r), r ++;
                r --, add(r);
                ans += r - l + 1;
            }
        }
        cout << ans << '\n';
    }
}

namespace Cor{
    int bit[31];
    ll ans = 0;

    bool ok(int i){
        if ( (a[i]&x) == a[i] ) return true;
        return false;
    }

    bool check(){
        int tmp = 0;
        for (int i = 0; i <= 30; i ++)
            if ( BIT(x, i) && !bit[i] ) return false;
        return true;
    }

    void add(int i){
        for (int j = 0; j <= 30; j ++)
            if ( BIT(a[i], j) ) bit[j] ++;
    }

    void sub(int i){
        for (int j = 0; j <= 30; j ++)
            if ( BIT(a[i], j) ) bit[j] --;
    }

    void solve(){
        int l = 1, r = 1;
        for (int i = 1; i <= n; i ++){
            if ( !ok(i) ) {
                l = r = i + 1;
                for (int j = 0; j <= 30; j ++ )
                    bit[j] = 0;
                continue;
            }

            add(i);

            if ( check() ){
                while ( check() && r <= i ) sub(r), r ++;
                r --; add(r);
                ans += r - l + 1;
            }
        }
        cout << ans << '\n';
    }
}

namespace Cxor{
    map<int, int> d;
    ll ans = 0;

    void solve(){
        int s = 0;
        d[0] = 1;
        for (int i = 1; i <= n; i ++)
            s ^= a[i], ans += d[s^x], d[s] ++;
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("bitop.in", "r") ){
        freopen("bitop.in", "r", stdin);
        freopen("bitop.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> x;

    Cand::solve();
    Cor::solve();
    Cxor::solve();

    return 0;
}
