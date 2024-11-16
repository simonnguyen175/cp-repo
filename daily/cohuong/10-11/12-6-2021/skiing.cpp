#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n;
pi a[N];
int bit[2][N], f[N][2];

bool cmp(pi a, pi b){
    return a.se < b.se;
}

void updatePre(int u, int v){
    for (; u <= N-5; u += u&(-u))
        bit[0][u] = max(bit[0][u], v);
}

int getPre(int u){
    int res = 0;
    for (; u >= 1; u -= u&(-u)){
        res = max(res, bit[0][u]);
    }
    return res;
}

void updateSuf(int u, int v){
    for (; u >= 1; u -= u&(-u))
        bit[1][u] = max(bit[1][u], v);
}

int getSuf(int u){
    int res = 0;
    for (; u <= N-5; u += u&(-u))
        res = max(res, bit[1][u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("skiing.inp", "r", stdin);
    freopen("skiing.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n, cmp);

    // f[i][0] tu trai sang phai
    // f[i][1] tu phai sang trai

    int ans = 0;

    for (int i = 1; i <= n; i ++){
        f[i][0] = getPre(a[i].fi) + 1;
        f[i][1] = getSuf(a[i].fi) + 1;
        ans = max({ans, f[i][0], f[i][1]});
        updatePre(a[i].fi, f[i][1]);
        updateSuf(a[i].fi, f[i][0]);
    }

    cout << ans;

    return 0;
}
