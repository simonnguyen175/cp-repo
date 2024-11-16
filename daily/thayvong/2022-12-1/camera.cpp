#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int h[N], suf[N], pre[N];
char d[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("camera.inp", "r") ){
        freopen("camera.inp", "r", stdin);
        freopen("camera.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];

    for (int i = 1; i <= n; i ++)
        cin >> d[i];

    stack<int> stk;
    for (int i = 1; i <= n; i ++){
        pre[i] = stk.size();
        while ( stk.size() && h[stk.top()] < h[i] ) stk.pop();
        stk.push(i);
    }
    while ( stk.size() ) stk.pop();
    for (int i = n; i >= 1; i --){
        suf[i] = stk.size();
        while ( stk.size() && h[stk.top()] < h[i] ) stk.pop();
        stk.push(i);
    }

    for (int i = 1; i <= n; i ++)
        if ( d[i] == 'W' ) cout << pre[i] << ' ';
        else cout << suf[i] << ' ';

    return 0;
}
