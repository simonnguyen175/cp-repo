#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

ll n, k;
ll a[N], f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    f[0] = 1;
    for (int i = 1; i <= n; i ++)
    for (int j = a[i]; j <= n; j ++)
        f[j] |= f[j-a[i]];

    for (int j = k; j >= 0; j --)
        if ( f[j] ) return cout << j, 0;

    return 0;
}
