#include<bits/stdc++.h>
#define simon "pairwood"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5 + 5;

int n, k, h[N], ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    sort(h + 1, h + 1 + n);

    int j = n / 2;
    for (int i = n; i > n / 2; i --){
        if ( j == 0 ) break;
        if ( h[i] - h[j] < k ){
            while ( h[i] - h[j] < k && j >= 1 ) j --;
            if ( j == 0 ) break;
            ans ++;
            j --;
        }
        else {ans ++; j --;}
    }

    cout << ans;

    return 0;
}

