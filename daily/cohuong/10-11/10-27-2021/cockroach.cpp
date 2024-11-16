#include<bits/stdc++.h>
#define simon "cockroachA"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, ans;
string s;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> s;
    ans = n;

    int mn, cntb = 0, cntr = 0;

    for (int i = 1; i <= n; i ++){
        char t;
        if ( i % 2 ) t = 'r';
        else t = 'b';
        if ( s[i-1] != t )
            if ( s[i-1] == 'b' ) cntb ++;
            else cntr ++;
    }
    mn = min(cntb, cntr);
    ans = min(ans,  cntb + cntr - mn);

    cntb = 0; cntr = 0;
    for (int i = 1; i <= n; i ++){
        char t;
        if ( i % 2 ) t = 'b';
        else t = 'r';
        if ( s[i-1] != t )
            if ( s[i-1] == 'b' ) cntb ++;
            else cntr ++;
    }
    mn = min(cntb, cntr);
    ans = min(ans,  cntb + cntr - mn);

    cout << ans;

    return 0;
}
