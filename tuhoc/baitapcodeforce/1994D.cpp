#include<bits/stdc++.h>
using namespace std;
const int N = 15;

int n, m;
int a[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];

        if ( n * m == 1 ) cout << -1 << '\n';
        else{
            if ( m > n ){
                for (int i = 1; i <= n; i ++){
                    int tmp = a[i][1];
                    for (int j = 1; j < m; j ++){
                        a[i][j] = a[i][j+1];
                    }
                    a[i][m] = tmp;
                }
            }
            else{
                for (int j = 1; j <= m; j ++){
                    int tmp = a[1][j];
                    for (int i = 1; i < n; i ++)
                        a[i][j] = a[i+1][j];
                    a[n][j] = tmp;
                }
            }

            for (int i = 1; i <= n; i ++){
                for (int j = 1; j <= m; j ++)
                    cout << a[i][j] << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}
