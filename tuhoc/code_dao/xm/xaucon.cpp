#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("xaucon.inp", "r", stdin);
    freopen("xaucon.out", "w", stdout);

    int test;
    cin >> test;
    string s;
    while ( test -- ){
        cin >> s;
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c ++){
            int mx1 = 0, mx2 = 0, cur = 0;
            for (int i = 0; i < s.size(); i ++){
                if ( (char)s[i] != (char)c ){
                    if ( mx1 <= cur ){
                        mx2 = mx1;
                        mx1 = cur;
                    }
                    else{
                        if ( mx2 < cur )
                            mx2 = cur;
                    }

                    cur = 0;
                }
                else cur ++;
            }

            if ( mx1 <= cur ){
                mx2 = mx1;
                mx1 = cur;
            }
            else{
                if ( mx2 < cur )
                    mx2 = cur;
            }

//            if ( c == 'y' )
//            cout << mx1 << ' ' << mx2 << '\n';

            if ( mx1 == mx2 ){
                ans = max(ans, mx1);
            }
            else ans = max(ans, mx1-1);
        }

        cout << ans << '\n';
    }

    return 0;
}
/*
2
bcaca
xyyzyy
*/
