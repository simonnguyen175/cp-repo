#include<bits/stdc++.h>
#define simon "numdist"
using namespace std;
const int MOD = 998244353;

int n;
int c[10][10];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        int rem = 8-s.size();
        for (int j = 1; j <= rem; j ++) s = '0' + s;
        for (int j = 0; j < s.size(); j ++){
            ans = add(ans, i-1-c[j][s[j]-'0']);
            c[j][s[j]-'0'] ++;
        }
    }
    cout << ans;

    return 0;
}
