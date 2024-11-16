#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    if( n == 1 ){
        cout << 1; return 0;
    }
    if( n == 2 ){
        cout << 2; return 0;
    }
    if( 3 <= n && n <= 6 ){
        cout << 3;
        return 0;
    }
    if( n >= 7 ){
        cout << 4;
        return 0;
    }
}
