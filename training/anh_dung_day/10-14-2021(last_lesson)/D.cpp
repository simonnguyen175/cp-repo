#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n;
long long a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    long long ans = 0;
    a[0] = a[n+1] = INT_MAX;
    for (int i = 1; i <= n; i ++){
        if ( a[i] < a[i+1] && a[i] < a[i-1] ) continue;
        if ( a[i] >= a[i+1] && a[i] > a[i-1] )
            ans += 2 * a[i];
        else
            if ( a[i] > a[i-1] || a[i] >= a[i+1] )
            ans += a[i];
    }

    cout << ans;
}
