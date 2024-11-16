#include<bits/stdc++.h>
using namespace std;

int t, n, m;
int l[10], r[10];

void solve(){
    cin >> n;
    for (int i = 1; i <= m; i ++)
        if ( l[i] <= n && n <= r[i] ){
            cout << "La premiere joueuse gagne.\n";
            return;
        }
    cout << "La deuxieme joueuse gagne.\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("mulgame.inp", "r") ){
        freopen("mulgame.inp", "r", stdin);
        freopen("mulgame.out", "w", stdout);
    }

    l[1] = 2, r[1] = 9;
    m = 1;
    while ( r[m] <= 1e9 ){
        m ++;
        l[m] = r[m-1] * 2 + 1;
        r[m] = l[m] + ( r[m-1] - l[m-1] + 1 ) * 18 - 1;
    }

    cin >> t;
    while ( t -- ) solve();
    return 0;
}
