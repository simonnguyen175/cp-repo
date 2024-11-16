#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
vector<int> a;
int id[71], d[71], pw2[N], f[2][1<<11];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

bool nto(int x){
    if ( x <= 1 ) return 0;
    for (int i = 2; i * i <= x; i ++)
        if ( x % i == 0 ) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for (int i = 1; i <= 35; i ++)
        if ( nto(i) ) id[i] = m ++;

    cin >> n;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        if ( x > 35 && nto(x) ) { d[x] ++; continue; }

        int msk = 0;
        for (int j = 2; j * j <= x; j ++) if ( x % j == 0 ){
            int cnt = 0;
            while ( x % j == 0 ) x /= j, cnt ++;
            if ( cnt % 2 ) msk |= (1<<id[j]);
        }
        if ( x != 1 ) msk |= (1<<id[x]);
        a.pb(msk);
    }

    n = a.size();
    f[1][0] = 1;
    for (int i = 0; i < n; i ++){
        int cur = i & 1, pre = cur ^ 1;
        for (int t = 0; t < (1<<m); t ++){
            f[cur][t] = f[pre][t];
            f[cur][t] = add(f[cur][t], f[pre][t^a[i]]);
        }
    }

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = add(pw2[i-1], pw2[i-1]);

    int ans = 1;
    for (int i = 36; i <= 70; i ++) if ( d[i] )
        ans = mul(ans, pw2[d[i]-1]);


    ans = mul(ans, f[(n-1)&1][0]);

    cout << ans - 1;

    return 0;
}
