#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9;

int m, A, B;
int a[15], b[15], ca[35], cb[35], sa[15], sb[15];
ll f[35][50][50];

void gen(int tt, int id, int nho1, int nho2){
    for (int i = 0; i <= 1; i ++){
        sa[tt] = sa[tt-1] + i * a[tt];
        sb[tt] = sb[tt-1] + i * b[tt];
        if ( tt == m ){
            if ( (sa[m] + nho1) % 2 == ca[id] && (sb[m] + nho2) % 2 == cb[id] )
                ( f[id][(sa[m]+nho1)/2][(sb[m]+nho2)/2] += f[id+1][nho1][nho2] ) %= MOD;
        }
        else gen(tt+1, id, nho1, nho2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> A >> B;

    for (int i = 30; i >= 1; i --)
        { ca[i] = A % 2; A /= 2; }
    for (int i = 30; i >= 1; i --)
        { cb[i] = B % 2; B /= 2; }

    for (int i = 1; i <= m; i ++)
        cin >> a[i] >> b[i];

    f[31][0][0] = 1;
    for (int i = 31; i >= 1; i --)
    for (int nho1 = 0; nho1 <= 49; nho1 ++)
    for (int nho2 = 0; nho2 <= 49; nho2 ++)
        if ( f[i][nho1][nho2] )
            gen(1, i - 1, nho1, nho2);

    cout << f[0][0][0];

    return 0;
}
