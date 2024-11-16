#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, k;
int row[N], col[N]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++){
        int x, y;
        cin >> x >> y;
        row[x] = 1; 
        col[y] = 1;
    }

    int subr = 0, subc = 0; 
    for (int i = 1; i <= n; i ++)
        if ( !row[i] ) subr ++;

    for (int i = 1; i <= m; i ++) 
        if ( !col[i] ) subc ++; 

    cout << 1ll * (n - subr) * (m - subc);    

    return 0; 
}   