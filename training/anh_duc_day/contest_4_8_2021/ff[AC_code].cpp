#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001, inf = 1e15;

ll n , m , a[N] , dp[N][101] , Min[N][101];

int main(){
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++){
        for (int k = 0 ; k < m - 1 ; k++){
            dp[i][k] = ((i - k - 1 >= 1 ) ? Min[i - k - 1][m - k - 2] : 0) + a[i - k];
            if (k != 0) Min[i][k] = min(Min[i][k - 1] , dp[i][k]);
            else Min[i][k] = dp[i][k];
        }
    }
    cout << Min[n][m - 2] ;
    return 0;
}
