#include<bits/stdc++.h>
using namespace std;
const int N = 35;

int m, n;
int b[35][35], a[35][35];
int row[] = {1, -1, 0, 0};
int col[] = {0, 0, 1, -1};
long long ans = 0;

void xuli(){
    bool flag = 1;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        int sum = 0;
        for (int k = 0; k < 4; k ++){
            int x = i + row[k], y = j + col[k];
            if ( x < 1 || x > m || y < 1 || y > n ) continue;
            sum += a[x][y];
        }
        if ( b[i][j] != (sum % 3) ){
            flag = 0;
            break;
        }
    }

    if ( flag ) ans ++;
}

void gen(int x, int y){
    for (int i = 0; i <= 2; i ++){
        a[x][y] = i;
        if ( x == m && y == n ) xuli();
        else{
            if ( y == n ) gen(x + 1, 1);
            else gen(x, y + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> b[i][j];

    gen(1, 1);

    cout << ans;

    return 0;
}
