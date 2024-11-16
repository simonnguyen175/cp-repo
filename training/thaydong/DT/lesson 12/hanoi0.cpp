#include<bits/stdc++.h>
using namespace std;

int n;
char c[3];

void go(int n, int a, int b){
    if ( n == 0 ) return;
    if ( b == (a+1)%3 ){
        go(n-1, a, 3-a-b);
        cout << c[a];
        go(n-1, 3-a-b, b);
    }
    else{
        go(n-1, a, b);
        cout << c[a];
        go(n-1, b, a);
        cout << c[3-a-b];
        go(n-1, a, b);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    c[0] = 'A', c[1] = 'B', c[2] = 'C';
    go(n, 0, 2);

    return 0;
}
