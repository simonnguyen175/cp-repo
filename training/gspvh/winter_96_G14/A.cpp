#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int MOD = 1e9 + 19972207;

int n, k;
int f[1<<24], pw[1<<24];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("urgent.inp", "r") ){
        freopen("urgent.inp", "r", stdin);
        freopen("urgent.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        int msk = 0;
        for (int j = 0; j < s.size(); j ++)
            msk |= (1<<(s[j]-'a'));
        f[msk] ++;
    }

    for (int i = 0; i < 24; i ++)
    for (int msk = 0; msk < (1<<24); msk ++)
        if ( BIT(msk, i) )
            f[msk] += f[msk^(1<<i)];

    pw[0] = 1;
    for (int i = 1; i < (1<<k); i ++)
        pw[i] = mul(pw[i-1], n+1);

    int ans = 0;
    for (int msk = 0; msk < (1<<k); msk ++)
        add(ans, mul(pw[msk], n-f[((1<<24)-1)^msk]));
    cout << ans;

    return 0;
}
