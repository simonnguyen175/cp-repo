#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, a[1005], temp = 0, mx;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> t;

    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        mx = a[1];
        temp = 0;
        for (int i = 1; i <= n; i ++){
            temp = max(temp,a[i]);
            mx = __gcd(mx,a[i]);
        }

        temp = temp/mx - n;
        if ( temp % 2 == 0 ) cout << "M\n";
        else cout << "DD\n";
    }

    return 0;
}
