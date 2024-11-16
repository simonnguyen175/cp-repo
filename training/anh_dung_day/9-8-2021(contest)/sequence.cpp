#include<bits/stdc++.h>
#define simon "sequence"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, a[N];

namespace sub1{
    bool checknum(int x, int y){
        bool flag = 0;
        while ( x ){
            if ( x % 10 == y){ flag = 1; break; }
            x /= 10;
        }
        return flag;
    }

    void solve(){
        for (int i = 1; i <= 1000; i ++)
            if ( checknum(i, a[1]) ){
                bool flag = 1;
                for (int j = i + 1, id = 2; j <= i + n - 1; j ++, id ++){
                    //cout << j << ' ' << a[id] << ' ' << checknum(j, a[id]) << '\n';
                    if ( !checknum(j, a[id]) ) { flag = 0; break; }
                }
                if ( flag == 1 ) { cout << i; return; }
            }
    }
}

namespace sub3{
    void solve(){
        int lim = 1;
        for (int i = 1; i <= 5; i ++){
            if ( lim < n ) lim *= 10;
            else break;
        }
        cout << a[1] * lim;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    if ( n <= 1000 ) {sub1::solve(); return 0;}

    if ( n <= 100000 ) {sub3::solve(); return 0;}
}

