#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll k;
bool hate[105][105];
int id[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("line.inp", "r") ){
        freopen("line.inp", "r", stdin);
        freopen("line.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int x, y;
        cin >> x >> y;
        hate[x][y] = hate[y][x] = 1;
    }

    for (int i = 1; i <= n; i ++)
        id[i] = i;

    int cnt = 0;
    do{
        bool ck = 1;
        for (int i = 2; i <= n; i ++)
            if ( hate[id[i]][id[i-1]] ) ck = 0;
        if ( ck == 1 ) cnt ++;
        if ( cnt == k ){
            for (int i = 1; i <= n; i ++)
                cout << id[i] << ' ';
            return 0;
        }
    }
    while ( next_permutation(id+1, id+1+n) );

    return 0;
}

