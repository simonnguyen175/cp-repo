#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, k;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("peaks.inp", "r", stdin);
    freopen("peaks.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++) a[i] = i;
    int ans = 0;
    do{
        int pks = 0;
        for (int i = 1; i <= n; i ++)
            if ( a[i] > a[i-1] && a[i] > a[i+1] ) pks ++;
        if ( pks == k ) ans ++;
    }while ( next_permutation(a + 1, a + 1 + n) );

    cout << ans % 239;

    return 0;
}
