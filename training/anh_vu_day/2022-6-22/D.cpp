#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 111539786;

string s;
int n, k;
int f[N][N], Next[N][2];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int get(int k){
    memset(f, 0, sizeof f);

    f[0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= k; j ++) if ( f[i][j] ){
        if ( j < k ) f[Next[i][0]][j+1] = add(f[Next[i][0]][j+1], f[i][j]);
        if ( j > 0 ) f[Next[i][1]][j-1] = add(f[Next[i][1]][j-1], f[i][j]);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = add(res, f[i][0]);

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> k;
    n = s.size();
    s = ' ' + s;

    // 0 = (
    // 1 = )
    Next[n][0] = Next[n][1] = n + 1;
    for (int i = n-1; i >= 0; i --){
        Next[i][0] = Next[i+1][0];
        Next[i][1] = Next[i+1][1];
        if ( s[i+1] == '(' ) Next[i][0] = i+1;
        if ( s[i+1] == ')' ) Next[i][1] = i+1;
    }

    cout << add(get(k), -get(k-1));

    return 0;
}
