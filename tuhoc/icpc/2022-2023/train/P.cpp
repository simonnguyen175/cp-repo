#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, f[N][N][2];

int main(){
    cin >> n;

    memset(f, 0, sizeof f);

    for (int i = 2; i <= n; i ++)
        f[0][i][1] = f[i][0][1] = f[0][i][0] = f[i][0][0] = oo;

    int row0 = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        int x; cin >> x;
        if ( x ){
            int c2 = 0, c5 = 0;
            while ( x % 2 == 0 ) f[i][j][0] ++, x /= 2;
            while ( x % 5 == 0 ) f[i][j][1] ++, x /= 5;
        }else row0 = i;

        for (int k = 0; k <= 1; k ++)
            f[i][j][k] += min(f[i-1][j][k], f[i][j-1][k]);
    }

    int k = f[n][n][1] < f[n][n][0];

    if ( row0 && f[n][n][k] >= 1 ){
        cout << 1 << '\n';
        for (int i = 2; i <= row0; i ++) cout << 'D';
        for (int i = 2; i <= n; i ++) cout << 'R';
        for (int i = row0 + 1; i <= n; i ++) cout << 'D';
    }
    else{
        cout << f[n][n][k] << '\n';
        int x = n, y = n;
        vector<char> ans;
        while ( x != 1 || y != 1 ){
            if ( f[x-1][y][k] < f[x][y-1][k] ) ans.push_back('D'), x --;
            else ans.push_back('R'), y --;
        }
        reverse(ans.begin(), ans.end());
        for (auto c : ans) cout << c;
    }

    return 0;
}
