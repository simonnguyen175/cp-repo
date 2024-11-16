#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;

int n;
bitset<N> d[N], tmp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        d[i][j] = x-'0';
    }

    long long ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++) if ( d[i][j] ){
        tmp = d[i] & d[j];
        tmp >>= j;
        ans += tmp.count();
    }

    cout << ans;

    return 0;
}
