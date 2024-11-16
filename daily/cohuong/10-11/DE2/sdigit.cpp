#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Q, L, R, ans;
int g[205], a[20];
ll f[20][205][2];

int get(int x){
    int tmp, nx;
    while ( x / 10 ){
        tmp = x;
        nx = 0;
        while ( tmp ) nx += tmp % 10, tmp /= 10;
        x = nx;
    }
    return x;
}

ll calc(int id, int sum, bool ok){
    if ( id == 20 ) return g[sum];

    if ( f[id][sum][ok] != -1 ) return f[id][sum][ok];

    ll res = 0;
    for (int c = 0; c <= max(a[id], ok*9); c ++)
        res += calc(id+1, sum+c, ok|(c<a[id]));

    f[id][sum][ok] = res;

    return res;
}

void solve(){
    cin >> L >> R;
    L --;
    ans = 0;

    for (int i = 19; i >= 1; i --) a[i] = L % 10, L /= 10;
    memset(f, -1, sizeof f);
    ans -= calc(1, 0, 0);

    for (int i = 19; i >= 1; i --) a[i] = R % 10, R /= 10;
    memset(f, -1, sizeof f);
    ans += calc(1, 0, 0);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sdigit.in", "r") ){
        freopen("sdigit.in", "r", stdin);
        freopen("sdigit.out", "w", stdout);
    }

    for (int i = 1; i <= 200; i ++)
        g[i] = get(i);

    cin >> Q;
    while ( Q -- )
        solve();

    return 0;
}
