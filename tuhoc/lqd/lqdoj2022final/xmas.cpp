#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, k;
int a[N];
int q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xmas.inp", "r", stdin);
    freopen("xmas.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    cin >> q;
    while ( q -- ){
        int l, r;
        cin >> l >> r;
        stack<int> stk;
        stk.push(a[l]);
        for (int i = l + 1; i <= r; i ++){
            if ( stk.size() &&  stk.top() + a[i] == k ) stk.pop();
            else stk.push(a[i]);
        }

        if ( stk.size() ) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
