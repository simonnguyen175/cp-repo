#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n;
ll a[N], f[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    // f[i][0] xet den i va dang la day tang
    // f[i][1] xet den i va dang la day giam

    for (int i = 2; i <= n; i ++){
        if ( a[i] >= a[i-1] ){
            f[i][0] = max(f[i-1][0] + a[i] - a[i-1], f[i-1][1]);
            f[i][1] = max(f[i-1][0], f[i-1][1]);
        }
        else{
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = max(f[i-1][0], f[i-1][1] + a[i-1]-a[i]);
        }
    }

    cout << max(f[n][0], f[n][1]);

    return 0;
}
