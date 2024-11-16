#include<bits/stdc++.h>
using namespace std;
const int N = 4e2 + 5;

int n;
string S;
int s[3][N], pos[3][N], f[N][N][N][3];

void ckmn(int &a, int b){
    if ( b == -1 ) return;
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

int sum(int t, int l, int r){
    if ( l > r ) return 0;
    return s[t][r] - s[t][l-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> S;
    S = ' ' + S;
    for (int i = 1; i <= n; i ++){
        s[0][i] = s[0][i-1];
        s[1][i] = s[1][i-1];
        s[2][i] = s[2][i-1];
        if ( S[i] == 'R' ) s[0][i] ++, pos[0][s[0][i]] = i;
        else if ( S[i] == 'G' ) s[1][i] ++, pos[1][s[1][i]] = i;
        else s[2][i] ++, pos[2][s[2][i]] = i;
    }

    memset(f, -1, sizeof f);
    /// f(r, g, y, 0/1/2)
    f[0][0][0][0] = f[0][0][0][1] = f[0][0][0][2] = 0;
    for (int i = 0; i <= s[0][n]; i ++)
    for (int j = 0; j <= s[1][n]; j ++)
    for (int k = 0; k <= s[2][n]; k ++)
    for (int t = 0; t <= 2; t ++ ) if ( f[i][j][k][t] != -1 ){
        if ( t != 0 && i + 1 <= s[0][n] ){
            ckmn(f[i+1][j][k][0], f[i][j][k][t] + sum(1, pos[1][j]+1, pos[0][i+1]) + sum(2, pos[2][k]+1, pos[0][i+1]));
        }
        if ( t != 1 && j + 1 <= s[1][n] ){
            ckmn(f[i][j+1][k][1], f[i][j][k][t] + sum(0, pos[0][i]+1, pos[1][j+1]) + sum(2, pos[2][k]+1, pos[1][j+1]));
        }
        if ( t != 2 && k + 1 <= s[2][n] ){
            ckmn(f[i][j][k+1][2], f[i][j][k][t] + sum(0, pos[0][i]+1, pos[2][k+1]) + sum(1, pos[1][j]+1, pos[2][k+1]));
        }
    }

    int ans = -1;
    for (int i = 0; i <= 2; i ++)
        ckmn(ans, f[s[0][n]][s[1][n]][s[2][n]][i]);
    cout << ans;

    return 0;
}
