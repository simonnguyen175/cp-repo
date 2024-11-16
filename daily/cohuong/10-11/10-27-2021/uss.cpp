#include<bits/stdc++.h>
#define simon "uss"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, k[3];

namespace sub2{
    void solve(){
	   cout << k[1] * k[2] - 1 << '\n';
	   for (int i = 0; i < k[1]; i ++){
            if ( i % 2 == 0 )
                for (int j = 0; j < k[2]; j ++){
                    if ( i == 0 && j == 0 ) continue;
                    cout << i << ' ' << j << '\n';
            }
            else
            for (int j = k[2] - 1; j >= 0; j --)
                cout << i << ' ' << j << '\n';
	   }
	}
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> k[i];
    if ( n == 2 ) sub2::solve();
    return 0;
}
