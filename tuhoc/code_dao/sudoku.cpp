#include<bits/stdc++.h>
using namespace std;
const int N = 405;

int n;
int a[N][N], ans[N][N];
bool drow[N][N], dcol[N][N], dblo[N][N];

int id(int x, int y){
    int u = (x-1)/n + 1;
    int v = (y-1)/n + 1;
    return (u-1)*n + v;
}

void gen(int x, int y){
    if ( a[x][y] ){
        ans[x][y] = a[x][y];
        if ( y == n*n && x == n*n ){
                for (int i = 1; i <= n*n; i ++){
                    for (int j = 1; j <= n*n; j ++)
                        cout << ans[i][j] << ' ';
                    cout << '\n';
                }
                exit(0);
        }
        else{
            if ( y == n*n) gen(x+1, 1);
            else gen(x, y+1);
        }
    }
    else{
        for (int c = 1; c <= n*n; c ++){
            if ( drow[x][c] || dcol[y][c] || dblo[id(x,y)][c] ) continue;
            drow[x][c] = dcol[y][c] =  dblo[id(x, y)][c] = 1;
            ans[x][y] = c;

            if ( y == n*n && x == n*n ){
                for (int i = 1; i <= n*n; i ++){
                    for (int j = 1; j <= n*n; j ++)
                        cout << ans[i][j] << ' ';
                    cout << '\n';
                }
                exit(0);
            }
            else{
                if ( y == n*n) gen(x+1, 1);
                else gen(x, y+1);
            }

            drow[x][c] = dcol[y][c] =  dblo[id(x, y)][c] = 0;
            ans[x][y] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n*n; i ++)
    for (int j = 1; j <= n*n; j ++){
        cin >> a[i][j];
        dblo[id(i, j)][a[i][j]] = 1;
        drow[i][a[i][j]] = 1;
        dcol[j][a[i][j]] = 1;
    }

    gen(1, 1);

    return 0;
}
