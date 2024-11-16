#include<bits/stdc++.h>
#define simon "numdist"
#define BIT(x, k) ((x>>k)&1)
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 998244353;

int n;
int a[N];
int pw11[10], cpat[N*200];
ll f[(1<<7)];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, ll b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int cost(int x, int y){
    int res = 0;
    for (int i = 0; i <= 7; i ++){
        if ( (x % 10) != (y % 10) ) res ++;
        x /= 10, y /= 10;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    int p8 = 0;
    pw11[0] = 1;
    for (int i = 1; i <= 7; i ++) pw11[i] = pw11[i-1] * 11;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j ++) a[i] = a[i] * 10 + (s[j]-'0');

        if ( s.size() == 8 ) { p8 = i; continue; }

        while ( s.size() < 7 ) s = '0' + s;

        for (int j = 0; j < (1<<7); j ++){
            int ptn = 0;
            for (int k = 0; k < 7; k ++) if ( BIT(j, k) )
                ptn += pw11[k] * (s[k] - '0');
            else ptn += pw11[k] * 10;
            cpat[ptn] ++;
        }
    }

    for (int i = 0; i <= pw11[7]; i ++) if ( cpat[i] ){
        int msk = i, t = 0;
        for (int j = 0; j < 7; j ++){
            if ( (msk%11) == 10 ) t += (1<<j);
            msk /= 11;
        }

        f[t] += 1ll * cpat[i] * ( cpat[i] - 1 ) / 2;
    }


    for (int i = 0; i < (1<<7); i ++)
    for (int j = 0; j < i; j ++) if ( (i & j) == j )
        f[i] -= f[j];

    int ans = 1;
    for (int i = 0; i < (1<<7); i ++)
        ans = mul(ans, Pow(__builtin_popcount(i), f[i]));
    if ( p8 ) for (int i = 1; i <= n; i ++) if ( i != p8 )
        ans = mul(ans, cost(a[p8], a[i]));

    cout << ans;

    return 0;
}
