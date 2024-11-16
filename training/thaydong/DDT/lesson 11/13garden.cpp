#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int base = 2;

int n, m;
int a[N], f[N][5][5][2];

int calc(int id, int l, int h, bool ok){
    if ( f[id][l+base][h+base][ok] != -1 ) return f[id][l+base][h+base][ok];

    if ( id > n ) return 1;

    int cnt = 0;

    if ( l > -2 )
        cnt = ( cnt + calc(id + 1, min(l-1, -1), max(h-1, -1), ok | (-1 != a[id])) ) % m;

    if ( h < 2 && (ok | (1 == a[id])) )
        cnt = ( cnt + calc(id + 1, min(l+1, 1), max(h+1, 1), ok | (1 != a[id])) ) % m;

    f[id][l+base][h+base][ok] = cnt;

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        char x; cin >> x;
        a[i] = ( x == 'L' ? -1 : 1 );
    }

    memset(f, -1, sizeof f);

    cout << calc(1, 0, 0, 0);

    return 0;
}
