#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 7e3 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], s[N][N];
ll cur, pre;
int l;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    s[0][0] = 1;

    for (int i = 1; i <= n; i ++){

        cur = 0, pre = a[i];
        l = i;

        for (int j = i; j >= 2; j --){
            cur += a[j]; pre -= a[j];
            while ( pre + a[l-1] <= cur && l >= 1 ) pre += a[--l];
            if ( pre <= cur ) ( s[i][j] = s[j-1][l] ) %= MOD;
        }

        s[i][1] = 1;

        for (int j = i; j >= 0; j --){
            s[i][j] = ( s[i][j+1] + s[i][j] ) % MOD;
        }
    }

    cout << s[n][1];

    return 0;
}
