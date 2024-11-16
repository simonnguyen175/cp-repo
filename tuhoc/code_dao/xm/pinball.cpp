#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, p;
string s;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("pinball.inp", "r", stdin);
    freopen("pinball.out", "w", stdout);

    cin >> n >> p;
    cin >> s;
    for (int i = 1; i <= n; i ++){
        if ( s[i-1] == '<' ) a[i] = 0;
        else a[i] = 1;
    }

    int ans = 2;
    int l = p, r = p, dir = a[p];
    int cnt = 0;
    while ( cnt <= 6 ){
        cnt ++;
//        cerr << l << ' ' << r << ' ' << dir << '\n';
        if ( dir == 0 ){
            while ( a[l-1] == 0 && l-1 >= 1 ){
                l --;
                ans ++;
            }
            ans ++, l --;

            if ( l == 0 ){
                break;
            }

            ans += r - l;
            dir = 1;
        }
        else{
            while ( a[r+1] == 1 && r+1 <= n ){
                r ++;
                ans ++;
            }
            ans ++, r --;

            if ( r == n ){
                break;
            }

            ans += r - l;
            dir = 0;
        }
//        cout << ans << '\n';
    }
    cout << ans;

    return 0;
}
