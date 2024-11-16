#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e4 + 5;

int n, d, mxp;
int c[N];
map<pi, int> f;

void Insert(int i, int j, int v){
    if ( i > mxp ) return;
    if ( f.find({i, j}) != f.end() ) f[{i, j}] = max(f[{i, j}], v);
    else f[{i, j}] = v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> d;
    for (int i = 1, p; i <= n; i ++){
        cin >> p;
        c[p] ++;
        mxp = max(mxp, p);
    }

    f[{d, d}] = c[d];
    f.insert({{d, d}, f[{d, d}]});
    int ans = 0;
    while ( f.size() ){
        auto it = f.begin();
        int i = it->fi.fi, j = it->fi.se, v = it->se;

        ans = max(ans, v);

        f.erase(it);

        if ( j ) Insert(i+j, j, v+c[i+j]);
        if ( j > 1 ) Insert(i+j-1, j-1, v+c[i+j-1]);
        Insert(i+j+1, j+1, v+c[i+j+1]);
    }

    cout << ans;

    return 0;
}
