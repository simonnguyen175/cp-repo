#include<bits/stdc++.h>
using namespace std;
const int N = 6e3 + 5;

int a, b, c, d, e;
int v[N][N], s[N][N], l[N];

int get(int x, int y, int len){
    return s[x][y] - s[x-len][y] - s[x][y-len] + s[x-len][y-len];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> a >> b >> c >> d >> e;
    int nl = 0;
    for (int i = d; i <= min(a, b); i += d)
        l[++nl] = i;

    for (int i = 1; i <= c; i ++){
        int x, y; cin >> x >> y; v[x][y] = 1;
    }

    for (int i = 1; i <= a; i ++)
    for (int j = 1; j <= b; j ++)
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + v[i][j];

    int best = 0;
    for (int i = d; i <= a; i ++)
    for (int j = d; j <= b; j ++)
        for (int k = best + 1; k * d <= min(i, j); k ++){
            int len = k * d;
            if ( get(i, j, len) <= e ) best = k;
            else break;
        }

    cout << best * d;

    return 0;
}
