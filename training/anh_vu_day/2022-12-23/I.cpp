#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        char x;
        cin >> x;
        if ( x[i][j] == '0' ) h[i][j] = 0;
        else h[i][j] = h[i-1][j] + 1;
    }

    for (int i = 1; i <= n; i ++){
        stack<int> stk;
        for (int j = 1; j <= n; j ++)
            for
    }

    return 0;
}
