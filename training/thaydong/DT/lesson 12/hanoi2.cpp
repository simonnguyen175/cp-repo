#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

int n, p;
string s;
char t[205];
int pw2[105];
int ans = 0;

void Move(int n, int id, char a, char b, char c){
    if ( !p ) return;
    if ( n == 1 ){
        t[id] = c;
        p --;
        return;
    }
    if ( p > pw2[n]-1 ){
        p -= pw2[n]-1;
        for (int i = 1; i <= n; i ++) t[id-i+1] = c;
        return;
    }
    Move(n-1, n-1, a, c, b);
    Move(1, n, a, b, c);
    Move(n-1, n-1, b, a, c);
}

void Move1(int n, int id, char a, char b, char c){
    if ( n == 0 ) return;
    if ( s[id] == a ){
        Move1(n-1, n-1, a, c, b);
    }
    if ( s[id] == c ){
        ans += pw2[n-1];
        Move1(n-1, n-1, b, a, c);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> p >> s;
    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = pw2[i-1] * 2;
    for (int i = 1; i <= n; i ++) t[i] = 'A';
    Move(n, n, 'A', 'B', 'C');
    for (int i = 1; i <= n; i ++) cout << t[i];
    cout << '\n';
    s = ' ' + s;
    Move1(n, n, 'A', 'B', 'C');
    cout << ans << '\n';

    return 0;
}
