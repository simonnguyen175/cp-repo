#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n, t;
int a[N], lpf[N], d[N];

void sieve(){
    for (int i = 2; i * i < N; i ++) if ( !lpf[i] )
    for (int j = i * i; j <= N; j += i)
        lpf[j] = i;

    for (int i = 1; i < N; i ++)
        if ( !lpf[i] ) lpf[i] = i;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    cin >> n;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x;
        while ( lpf[x] != 1 ){
            y = lpf[x];
            while ( x % y == 0 ){
                x /= y;
                d[y] ++;
            }
        }
    }

//    for (int i = 1; i <= 10; i ++)
//        cout << lpf[i] << ' ';
//    cout << '\n';

    cin >> t;
    while ( t -- ){
        int x, p, y, cy;
        cin >> x >> p;
        bool ck = 1;
        while ( lpf[x] != 1 ){
            y = lpf[x];
            cy = 0;

            while ( x % y == 0 ){
                x /= y;
                cy ++;
            }

            if ( 1LL * cy * p > d[y] ){
                ck = 0;
                break;
            }
        }
        cout << ck;
    }

    return 0;
}
