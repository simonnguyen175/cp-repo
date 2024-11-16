#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int c[N];

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        cin >> c[i];
    set<pi> diff; 
    for (int i = 2; i <= n; i ++)
        diff.pb({c[i] - c[i-1], i}); 

    if ( m > n ){
        cout << max(m - n, *diff.rbegin(),first); 
    }  
    else{ 
        for (int i = 1; i <= m-n; i ++){
            auto it = diff.begin(); 
            diff.del({})
        }
    }

    return 0; 
}