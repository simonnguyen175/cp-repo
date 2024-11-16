#include<bits/stdc++.h>
using namespace std;
const int MX = 1e9;



void solve(int id, int l){
    if ( vis[id][l] ) return;
    if ( id == 1001 ) return;
    f[id][l] = 0;
    if ( l >= i - l ){
        solve(id + 1, l);
        f[id][l] = f[id][l], f[id+1][l]);

        solve(id + 1, l + 1);
        f[id][l] = add(f[id][l], f[id+1][l+1]);
    }
    else{
        solve(id + 1, l);
        f[id][l] = add(f[id][l], f[id+1][l]);
    }
    vis[id][l] = 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    f[1001][]
    solve(1, 0);

    while ( cin >> type ){
        if ( type == 1 ){
            cin >> n >> k;
            n *= 2;
        }

        if ( type == 2 ){
            cin >> n;
            n *= 2;
            for (int i = 1; i <= n; i ++)
                cin >> a[i];
        }
    }

    return 0;
}
