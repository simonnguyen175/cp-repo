#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], b[N][5];

bool cmp(int x, int y){
    int cnt = 0;
    for (int i = 1; i <= 5; i ++)
        if ( b[x][i] < b[y][i] ) cnt ++;
    return cnt >= 3;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("chupanh.inp", "r") ){
        freopen("chupanh.inp", "r", stdin);
        freopen("chupanh.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= 5; i ++)
    for (int j = 1; j <= n; j ++){
        int x; cin >> x;
        b[x][i] = j;
    }

    for (int i = 1; i <= n; i ++) a[i] = i;
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i ++) cout << a[i] << ' ';

    return 0;
}
