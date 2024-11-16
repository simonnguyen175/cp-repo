#include<bits/stdc++.h>
using namespace std;
const int N = 105;

int k, n, m;
struct racer{
    int laps, timer, id;
} racers[N];

int lap(int x){
    return ( x % k ? x % k : k );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("duaxe.inp", "r", stdin);
    freopen("duaxe.out", "w", stdout);

    cin >> k >> n >> m;
    for (int i = 1; i <= n; i ++) racers[i] = {0, 0, i};
    for (int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        int cur = lap(racers[x].laps);
        if ( lap(cur+1) == y )
            racers[x] = {racers[x].laps + 1, i, x};
    }

    sort(racers + 1, racers + 1 + n, [&](racer a, racer b){
        if ( a.laps != b.laps ) return a.laps > b.laps;
        if ( a.timer != b.timer ) return a.timer < b.timer;
        return true;
    });

    for (int i = 1; i <= n; i ++)
        cout << racers[i].id << ' ';

    return 0;
}
