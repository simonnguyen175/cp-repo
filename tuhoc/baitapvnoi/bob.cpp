#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        cin >> a[i][j];
        s[i][j] = ( a[i-1][j] != a[i][j] ? 1 : s[i-1][j] + 1 );
    }

    deque<int> dq;
    for (int i = 1; i <= n; i ++){
        dq.clear();
        for (int j = 1; j <= n; j ++){

        }
    }
}
