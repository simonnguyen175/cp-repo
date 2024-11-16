#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e6;

int n, l;
char type1[6][35], type2[6][35];
int s[2][35], p[2][35], Next[2][35][35], f[35][35][35];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> l;
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= l; j ++)
            cin >> type1[i][j];
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= l; j ++)
            cin >> type2[i][j];

    memset(s, 0, sizeof s);

    for (int i = 1; i <= l; i ++){
        int mu2 = 1;
        for (int j = 1; j <= 5; j ++){
            if ( type1[j][i] == '#' ) s[0][i] += mu2;
            if ( type2[j][i] == '#' ) s[1][i] += mu2;
            mu2 *= 2;
        }
    }

    for (int t = 0; t <= 1; t ++){
        p[t][1] = 0;
        for (int i = 2; i <= l; i ++){
            int k = p[t][i-1];
            while ( k > 0 && s[t][k+1] != s[t][k] ) k = p[t][k];
            if ( s[t][k+1] == s[t][i] ) p[t][i] = k + 1;
        }

        Next[t][0][s[t][1]] = 1;
        for (int i = 1; i < l; i ++)
            for (int c = 0; c <= 31; c ++)
                if ( c == s[t][i+1] ){
                    Next[t][i][c] = i + 1;
                    continue;
                }
                else{
                    int k = p[t][i];
                    while ( k > 0 && s[t][k+1] != c ) k = p[t][k];
                    if ( s[t][k+1] == c ) Next[t][i][c] = k + 1;
                }
    }

    for (int c = 0; c <= 31; c ++)
        Next[0][l][c] = Next[1][l][c] = l;

    f[0][0][0] = 1;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= l; j ++)
            for (int k = 0; k <= l; k ++)
                for (int c = 0; c <= 31; c ++)
                    f[i+1][Next[0][j][c]][Next[1][k][c]] = ( f[i+1][Next[0][j][c]][Next[1][k][c]] + f[i][j][k] ) % MOD;

    int res = 0;
    for (int i = 0; i < l; i ++)
        res = ( res + f[n][i][l] + f[n][l][i] ) % MOD;

    cout << res;

    return 0;
}
