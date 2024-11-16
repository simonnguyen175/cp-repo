#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const ll oo = 1e15;

int n, k, x;
ll ans = -oo;
map<ll, int> vis[N];
int add[N][2], chess[N], bong[N];

void go(int id, ll rate){
    if ( id == n ) { ans = max(ans, rate); return; }

    if ( x - k <= rate && rate <= x + k ){
        if ( vis[id][rate-x+k] ) return;
        vis[id][rate-x+k] = 1;
        go(id+1, rate + add[id+1][chess[id+1]]);
        go(id+1, rate + add[id+1][bong[id+1]]);
    }
    else if ( rate < x - k ) go(id+1, rate+add[id+1][chess[id+1]]);
    else if ( rate > x + k ) go(id+1, rate+add[id+1][bong[id+1]]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i ++){
        cin >> add[i][1] >> add[i][0] >> chess[i] >> bong[i];
        add[i][0] *= -1;
    }

    go(0, x);

    cout << ans;

    return 0;
}
