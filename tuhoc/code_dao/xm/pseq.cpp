#include<bits/stdc++.h>
#define int long long
using namespace std;

bool nto(int x){
    if ( x <= 1 ) return 0;
    for (int i = 2; i * i <= x; i ++){
        if ( x % i == 0 ) return 0;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("pseq.inp", "r", stdin);
    freopen("pseq.out", "w", stdout);

    int test, a1, a2;
    cin >> test;
    while ( test -- ){
        cin >> a1 >> a2;
        if ( a1 >= a2 ){
            cout << -1;
            continue;
        }

        if ( nto(a2 - a1) ){
            cout << 2 << '\n';
            continue;
        }

        if ( a1 == 2 ){ // th a1 = 2 thi thang o giua phai le suy ra thang o giua cach a1 le, cach a2 chan = 2
            if ( nto(a2 - 2) && nto(a2 - 2 - 2) ) // chen a2 - 2
                cout << 3 << '\n';
        }
        else{ // th 2 so deu le suy ra so o giua cung le suy ra cach deu 2 voi 2 ben a1 a2
            if ( a2 - a1 == 4 ){
                if ( nto(a1 + 2) )
                    cout << 3 << '\n';
                else cout << -1;
            }
            else{
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}

/*
2
5 7
11 37
*/
