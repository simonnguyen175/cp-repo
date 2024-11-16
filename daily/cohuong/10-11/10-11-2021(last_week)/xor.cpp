#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int t, n, tt;
int a[N], trie[30*N][2];

void Insert(int x){
    int cur = 0;
    for (int i = 30; i >= 0; i --){
        if ( trie[cur][BIT(x, i)] == -1 )
            trie[cur][BIT(x, i)] = ++ tt;
        cur = trie[cur][BIT(x, i)];
    }
}

int Get(int x){
    int res = 0, cur = 0;
    for (int i = 30; i >= 0; i --){
        if ( trie[cur][1-BIT(x, i)] != -1 ){
            res += (1<<i);
            cur = trie[cur][1-BIT(x, i)];
        }
        else
            cur = trie[cur][BIT(x, i)];
    }
    return res;
}

void solve(){
    cin >> n;

    tt = 0;
    for (int i = 0; i <= 30*n; i ++)
        trie[i][0] = trie[i][1] = -1;

    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        Insert(a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, Get(a[i]));

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xor.inp", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
