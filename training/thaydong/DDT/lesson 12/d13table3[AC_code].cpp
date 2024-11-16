#include<bits/stdc++.h>
using namespace std;
const int MOD = 111539786;

int m, n, k = 0;
int b[35][35], c[35*35][35*35], id[35][35];
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> b[i][j];

    int cnt = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            id[i][j] = ++ cnt;

    int N = m * n;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            c[id[i][j]][N+1] = b[i][j];
            for (int k = 0; k < 4; k ++){
                int x = i + row[k], y = j + col[k];
                if ( x < 1 || x > m || y < 1 || y > n ) continue;
                c[id[i][j]][id[x][y]] = 1;
            }
        }

    for (int i = 1; i <= N; i ++){
        bool ok = 0;

        for (int j = 1; j <= N; j ++)
            if ( c[i][j] != 0 ){
                for (int x = i + 1; x <= N; x ++)
                    if ( c[x][j] != 0 ){
                        int hs;
                        if ( c[i][j] == c[x][j] ) hs = 2;
                        else hs = 1;
                        for (int y = 1; y <= N + 1; y ++)
                            c[x][y] = ( c[x][y] + hs * c[i][y] ) % 3;
                    }
                ok = 1;
                break;
            }

        if ( !ok )
            if ( c[i][N+1] == 0 ) k ++;
            else{
                cout << 0;
                return 0;
            }
    }

    long long ans = 1;
    for (int i = 1; i <= k; i ++)
        ( ans *= 3 ) %=  MOD;

    cout << ans;

    return 0;
}
