#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t, n;
    cin >> t;
    while ( t -- ){
        cin >> n;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i ++){
            int x;
            cin >> x;
            if ( x == 1 ) c1 ++;
            else if ( x == 2 ) c2 ++;
            else{
                c1 += x - 2;
                c2 ++;
            }
        }
        cout << c1/2 + c2/2 << '\n';
    }

    return 0;
}
