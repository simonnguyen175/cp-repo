#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int S = 1e3 + 2; 

int n, s;
int a[N], lef[N][S]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 

    cin >> n >> s;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i]; 
    
    for (int i = 1; i <= n; i ++){ 
        for (int j = 1; j <= s; j ++){ 
            lef[i][j] = lef[i-1][j];  
            if ( j > a[i] ) 
                lef[i][j] = max(lef[i][j], lef[i-1][j-a[i]]); 
        }
        lef[i][a[i]] = i;
    }

    int ans = n+1; 
    for (int i = 1; i <= n; i ++) if ( lef[i][s] )
        ans = min(ans, i - lef[i][s] + 1);

    if ( ans == n + 1 ) cout << -1; 
    else cout << ans; 

    return 0;  
}