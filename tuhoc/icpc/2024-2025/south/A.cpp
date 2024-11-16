#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;

int n, m;
long long bit[N][N][4*N];

void update(int x, int y, int z, int w){
    int del = w - a[x][y][z];
    for (int i = x; i <= n; i += i&(-i)){}
}

void solve(){
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
    for (int k = 1; k <= 4*n; k ++)
        bit[i][j][k] = a[i][j][k] = 0;

    cin >> n >> m;
    string type;
    while ( m -- ){
        cin >> type;

        int x, y, z, w;
        int x1, x2, y1, y2, z1, z2;
        if ( type == "UPDATE" ){
            cin >> x >> y >> z >> w;
            update(x, y, z, w);
            a[x][y][z] = w;
        }
        else{
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << query(x1, y1, z1, x2, y2, z2) << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        solve();
    }
}
