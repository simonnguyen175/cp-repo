#include<bits/stdc++.h>
using namespace std;

int n, m, a, b;

int line(int x){
    return ( x % m ? x/m + 1 : x/m );
}

int col(int x){
    return ( x % m ? x%m : m );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> a >> b;


    if ( line(a) == line(b) ){
        cout << 1 << '\n';
        cout << col(a)-1 << ' ' << line(a)-1 << ' ' << col(b) << ' ' << line(a) << '\n';
        return 0;
    }

    if ( b == n ){
        if ( col(a) == 1 ){
            cout << 1 << '\n';
            cout << 0 << ' ' << line(a)-1 << ' ' << m << ' ' << line(b) << '\n';
        }
        else{
            cout << 2 << '\n';
            cout << col(a)-1 << ' ' << line(a)-1 << ' ' << m << ' ' << line(a) << '\n';
            cout << 0 << ' ' << line(a) << ' ' << ( line(b) == line(a) + 1 ? col(b) : m ) << ' ' << line(b) << '\n';
        }
        return 0;
    }

    if ( col(a) == 1 && col(b) == m ){
        cout << 1 << '\n';
        cout << 0 << ' ' << line(a)-1 << ' ' << m << ' ' << line(b) << '\n';
        return 0;
    }

    if ( col(a) != 1 && col(b) == m ){
        cout << 2 << '\n';
        cout << col(a)-1 << ' ' << line(a)-1 << ' ' << m << ' ' << line(a) << '\n';
        cout << 0 << ' ' << line(a) << ' ' << m << ' ' << line(b) << '\n';
        return 0;
    }

    if ( col(a) == 1 && col(b) != m ){
        cout << 2 << '\n';
        cout << 0 << ' ' << line(a)-1 << ' ' << m << ' ' << line(b)-1 << '\n';
        cout << 0 << ' ' << line(b)-1 << ' ' << col(b) << ' ' << line(b) << '\n';
        return 0;
    }

    if ( col(a) != 1 && col(b) != m ){
        if ( line(b) == line(a) + 1 ){
            cout << 2 << '\n';
            cout << col(a)-1 << ' ' << line(a)-1 << ' ' << m << ' ' << line(a) << '\n';
            cout << 0 << ' ' << line(b)-1 << ' ' << col(b) << ' ' << line(b) << '\n';
        }
        else{
            cout << 3 << '\n';
            cout << col(a)-1 << ' ' << line(a)-1 << ' ' << m << ' ' << line(a) << '\n';
            cout << 0 << ' ' << line(a) << ' ' << m << ' ' << line(b)-1 << '\n';
            cout << 0 << ' ' << line(b)-1 << ' ' << col(b) << ' ' << line(b) << '\n';
        }
        return 0;
    }

    return 0;
}
