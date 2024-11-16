#include<bits/stdc++.h>
using namespace std;

int n, k;
int p[2005];        

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) 
        cin >> p[i], p[i] --; 
    
    sort(p + 1, p + 1 + n);
    
    int cur = n, ans = 0;
    while ( cur > k ){
        ans += 2 * p[cur];
        cur -= k;  
    }

    if ( cur ) ans += 2 * p[cur]; 

    cout << ans;

    return 0; 
}