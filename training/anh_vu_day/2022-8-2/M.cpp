#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 998244353;

int n;
int a[N], f[N][2], g[N][2];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    f[0][0] = 1;
    g[0][0] = 1;
    stack<int> stk;
    for (int i = 1; i <= n; i ++){
        while ( stk.size() && a[stk.top()] > a[i] )
            stk.pop();
        if ( stk.size() ){
            f[i][0] = add(f[stk.top()][0], mul(add(g[i-1][1], -g[stk.top()-1][1]), a[i]));
            f[i][1] = add(f[stk.top()][1], mul(add(g[i-1][0], -g[stk.top()-1][0]), a[i]));
        }
        else{
            f[i][0] = mul(g[i-1][1], a[i]);
            f[i][1] = mul(g[i-1][0], a[i]);
        }

//        cout << i << ' ' << f[i][0] << ' ' << f[i][1] << '\n';

        g[i][0] = add(g[i-1][0], f[i][0]);
        g[i][1] = add(g[i-1][1], f[i][1]);
        stk.push(i);
    }

    if ( n % 2 ) cout << add(f[n][1], -f[n][0]);
    else cout << add(f[n][0], -f[n][1]);

    return 0;
}
