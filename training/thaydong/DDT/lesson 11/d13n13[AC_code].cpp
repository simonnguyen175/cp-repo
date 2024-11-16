#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 111539786;

ll A, B;
ll f[20][10][2];
int a[20], b[20];

ll calca(int i, int c, bool OK){
    if ( f[i][c][OK] != -1 ) return f[i][c][OK];
    if ( i > 16 ) return 1;
    ll cnt = 0;
    for (int nc = 0; nc <= max(OK*9, a[i]); nc ++)
        if ( c*10 + nc != 13 )
            ( cnt += calca(i+1, nc, OK|(nc < a[i])) );
    f[i][c][OK] = cnt;
    return cnt;
}

ll calcb(int i, int c, bool OK){
    if ( f[i][c][OK] != -1 ) return f[i][c][OK];
    if ( i > 16 ) return 1;
    ll cnt = 0;
    for (int nc = 0; nc <= max(OK*9, b[i]); nc ++)
        if ( c*10 + nc != 13 )
            ( cnt += calcb(i+1, nc, OK|(nc < b[i])) );
    f[i][c][OK] = cnt;
    return cnt;
}

void solve(ll A, ll B){
    for (int i = 16; i >= 1; i --) b[i] = B % 10, B /= 10;

    if ( A == 0 ){
        memset(f, -1, sizeof f);
        ll cntb = calcb(1, 0, 0);
        cout << cntb << '\n';
        return;
    }

    A --;
    for (int i = 16; i >= 1; i --) a[i] = A % 10, A /= 10;

    memset(f, -1, sizeof f);
    ll cnta =  calca(1, 0, 0);

    memset(f, -1, sizeof f);
    ll cntb = calcb(1, 0, 0);

    cout << cntb - cnta << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> A >> B ) solve(A, B);

    return 0;
}
