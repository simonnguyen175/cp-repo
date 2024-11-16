#include<bits/stdc++.h>
#define simon "bper"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int MOD = 1e9 + 7;

int n;
ll scs[1<<19], f[1<<19][51];

struct digit{
    int sl, s1, s2;
};

digit anal(int x){
    int sl = 0, s1 = 0, s2 = 0;
    while ( x ){
        if ( sl % 2 == 0 ) s1 += x % 10;
        else s2 += x % 10;
        sl ++;
        x /= 10;
    }
    if ( sl % 2 ) return {sl, s1, s2};
    else return {sl, s2, s1};
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    while ( cin >> n ){
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += anal(i).s1 + anal(i).s2;

    if ( sum % 2 ) { cout << 0 << '\n'; continue; }

    memset(f, 0, sizeof f);
    memset(scs, 0, sizeof scs);

    f[0][0] = 1;

    for (int t = 1; t < (1<<n); t ++)
        for (int i = 1; i <= n; i ++)
            if ( BIT(t, i-1) )
                scs[t] += anal(i).sl;

    for (int t = 0; t < (1<<n); t ++)
    for (int d = 0; d <= sum/2; s ++) if ( f[t][s] ){
        //cout << "f[" << t << "][" << s << "] = " << f[t][s] << '\n';
        for (int j = 1; j <= n; j ++)
            if ( !BIT(t, j-1) ){
                digit tmp = anal(j);
                if ( scs[t] % 2 == 0 ){
                    if ( s + tmp.s1 <= sum/2 )
                        ( f[t|(1<<(j-1))][s+tmp.s1] += f[t][s] ) %= MOD;
                }
                else if ( s + tmp.s2 <= sum/2 )
                    ( f[t|(1<<(j-1))][s+tmp.s2] += f[t][s] ) %= MOD;
            }
    }
    }
    return 0;
}
