#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

struct green{
    int x, y, z, id;
    bool operator < (const green &a) const{
        if ( y != a.y ) return y < a.y;
        else return x < a.x;
    }
};

struct node{
    int energy, steps, id, real;
};

node combine(node a, node b){
    if ( a.energy == b.energy ){
        if ( a.steps == b.steps ){
            if ( a.real < b.real ) return a;
            else return b;
        }
        else if ( a.steps < b.steps ) return a;
        else return b;
    }
    else if ( a.energy > b.energy ) return a;
    else return b;
}

int n, k;
green a[N];
node row[N], col[N], f[N];
int trace[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("greenfrog.inp", "r", stdin);
    freopen("greenfrog.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].id = i;
    }

    for (int i = 0; i <= 100000; i ++)
        row[i] = col[i] = {-1, 0, 0, 0};

    for (int i = 1; i <= n; i ++)
        f[i] = {-1, 0, 0, 0};

    int pos, pos1;

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
        if ( a[i].id == 1 ) pos1 = i, f[i] = {a[i].z, 1, i, 1}, trace[i] = 0;

    row[a[pos1].y] = col[a[pos1].x] = f[pos1];

    for (int i = pos1 + 1; i <= n; i ++){
        if ( row[a[i].y].energy >= k ) f[i] = row[a[i].y];
        if ( col[a[i].x].energy >= k ) f[i] = combine(f[i], col[a[i].x]);

        if ( f[i].energy == -1 ) continue;

        trace[i] = f[i].id;

        f[i].energy += a[i].z - k;
        f[i].steps ++;
        f[i].id = i;
        f[i].real = a[i].id;

        row[a[i].y] = combine(row[a[i].y], f[i]);
        col[a[i].x] = combine(col[a[i].x], f[i]);

        if ( a[i].id == n ) pos = i;
    }


    vector<pi> ans;
    ans.pb({a[pos].x, a[pos].y});

    while ( trace[pos] ){
        pos = trace[pos];
        ans.pb({a[pos].x, a[pos].y});
    }

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it.fi << ' ' << it.se << '\n';

    return 0;
}
