#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i ++)
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

int t, n, k, b;
ii a[N];

bool cmp (ii a, ii b){
    return a.se < b.se;
}

void solve(){
    cin >> n >> k >> b;
    FOR(i, 1, n)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n, cmp);

    int cnt = 0;
    for (int i = 1; i <= n; i ++)
}

int main(){
    FASTio
    cin >> t;
    while ( t -- ) solve();
    return 0;
}
