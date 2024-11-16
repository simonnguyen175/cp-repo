#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5+5;

int q, l, r, k;
int g[10][N];

void anal(int x){
    int k = x;
    while ( k >= 10 ){
        int tmp = 1;
        while ( k > 0 ){
            if ( k % 10 != 0 ) tmp *= k % 10;
            k /= 10;
        }
        k = tmp;
    }
    g[k][x] ++;
}

void init(){
    memset(g, 0, sizeof g);
    for (int i=1; i<=N; i++)
        anal(i);
    for (int i=1; i<=9; i++)
        for (int j=1; j<=N; j++)
            g[i][j] += g[i][j-1];
}

int main(){
    FASTio
    init();
    cin >> q;
    for (int i=1; i<=q; i++){
        cin >> l >> r >> k;
        cout << g[k][r] - g[k][l-1]<<'\n';
    }
    return 0;
}
