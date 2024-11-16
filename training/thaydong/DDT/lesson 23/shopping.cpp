#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        d[x] ++;
    }

    int n = 0;
    for (auto it : d)
        a[++n] = {it.fi, it.se};
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++)
    for (int i = 1; i <= n; i ++){

    }

    return 0;
}
