#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
char c[3];
string ans;
bool g[3][3];

void go(int n, int a, int b){
    if ( n == 0 ) return;
    if ( g[a][b] ){
        go(n-1, a, 3-a-b);
        ans += (char)c[a];
        ans += (char)c[b];
        ans += '\n';
        go(n-1, 3-a-b, b);
    }
    else{
        go(n-1, a, b);
        ans += (char)c[a];
        ans += (char)c[3-a-b];
        ans += '\n';
        go(n-1, b, a);
        ans += (char)c[3-a-b];
        ans += (char)c[b];
        ans += '\n';
        go(n-1, a, b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i <= 2; i ++)
    for (int j = 0; j <= 2; j ++)
        cin >> g[i][j];
    c[0] = 'A', c[1] = 'B', c[2] = 'C';
    go(n, 0, 2);
    cout << ans.size()/3 << '\n';
    cout << ans;

    return 0;
}
