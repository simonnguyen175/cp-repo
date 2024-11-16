#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k;
int a[N], d[N], f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    int pos = n + 1;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        d[a[i]] ++;
        if ( d[a[i]] == 1 ) cnt ++;
        if ( cnt >= k ){
            pos = i;
            break;
        }
    }

    f[pos] = 1;
    int j = 1; int res = 0;
    for (int i = pos + 1; i <= n; i ++){
        d[a[i]] ++;
        f[i] = 1;
        while ( d[a[j]] > 1 && j < i ){
            d[a[j]] --;
            res += f[j];
            res %= MOD;
            j ++;
        }
        f[i] += res % MOD;
    }

    cout << f[n];

    return 0;
}
