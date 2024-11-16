#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N = 2e4 + 5;
const int MOD = 1e9 + 7;

int n, q;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
struct factors{
    int v[17];
    double clog = 0;
} fact[N][15], inf, ans[N];
int res[N];

factors combine(factors &a, factors &b){
    factors res;
    for (int i = 0; i < 17; i ++){
        res.v[i] = max(a.v[i], b.v[i]);
        res.clog += (double)log2(prime[i]) * 1.0 * res.v[i];
    }
    return res;
}

factors get(int l, int r){
    int k = __lg(r-l+1);
    return combine(fact[l][k], fact[r-(1<<k)+1][k]);
}

int cmp(factors &a, factors &b){
    if ( a.clog == b.clog ) return 0;
    else if ( a.clog > b.clog ) return 1;
    else return -1;
}

factors ckmn(factors a, factors b){
    int tmp = cmp(a, b);
    if ( tmp <= 0 ) return a;
    else return b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        for (int j = 0; j < 17; j ++) if ( x % prime[j] == 0 ){
            int cnt = 0;
            while ( x % prime[j] == 0 ) cnt ++, x /= prime[j];
            fact[i][0].v[j] = cnt;
            fact[i][0].clog += (double)log2(prime[j]) * 1.0 * cnt;
        }
    }

    for (int j = 1; j <= __lg(n); j ++)
    for (int i = 1; i <= n - (1<<j) + 1; i ++)
        fact[i][j] = combine(fact[i][j-1], fact[i+(1<<(j-1))][j-1]);

    inf.clog = 1e9;
    for (int i = 1; i <= n+1; i ++) ans[i] = inf;

    for (int i = 1; i <= n; i ++){
        int p = i;
        factors cur = fact[i][0];

//        cout << i << " : \n";
        while ( p <= n ){
            int lo = p, hi = n, np;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                factors tmp = get(i, mid);
                if ( cmp(tmp, cur) == 0 ) np = mid, lo = mid + 1;
                else hi = mid - 1;
            }

//            cout << "update " << p << ' ' << np << " : ";
//            for (int j = 0; j < 17; j ++)
//                cout << cur.v[j] << ' ';
//            cout << '\n';

            ans[np-i+1] = ckmn(ans[np-i+1], cur);

            p = np + 1;
            cur = get(i, p);
        }
    }

    for (int i = n; i >= 1; i --){
        ans[i] = ckmn(ans[i], ans[i+1]);
        res[i] = 1;
        for (int j = 0; j < 17; j ++)
        for (int k = 1; k <= ans[i].v[j]; k ++)
            res[i] = 1ll * res[i] * prime[j] % MOD;
    }

    while ( q -- ){
        int x;
        cin >> x;
        cout << res[x] << '\n';
    }

    return 0;
}
