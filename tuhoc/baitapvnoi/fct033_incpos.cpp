#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, q, ans = 0;
ll a[N];

void xuli(int id, int x){
    if ( !id || id == n ) return;
    if ( a[id] >= 0 && a[id] + x < 0 ) ans ++;
    if ( a[id] < 0 && a[id] + x >= 0 ) ans --;
    a[id] += x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        a[i] = a[i+1] - a[i];
        if ( a[i] < 0 && i < n ) ans ++;
    }

    int l, r, x;
    while ( q -- ){
        cin >> l >> r >> x;
        xuli(l-1, x);
        xuli(r, -x);
        cout << ans << '\n';
    }

    return 0;
}
