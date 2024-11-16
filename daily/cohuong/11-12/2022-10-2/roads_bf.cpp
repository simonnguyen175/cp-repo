#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;

int n, m, k;
int row[N], col[N], ans[5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++){
        char type;
        int x;
        cin >> type >> x;
        if ( type == 'H' ) row[x] = 1;
        else col[x] = 1;
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        int k = row[i-1] + row[i] + col[j-1] + col[j];
        ans[k] ++;
    }

    for (int i = 0; i <= 4; i ++)
        cout << ans[i] << ' ';

    return 0;
}
