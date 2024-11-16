#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int MOD = 1e9 + 9;
const int base = 7;

int n;
string s;
int pre[N], suf[N];
int h[N], pw[N];
map<int, int> d;

int get(int l, int r){
    return (h[r] - 1ll * h[l-1] * pw[r-l+1] + 1ll*MOD*MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> s;
    s = ' ' + s;

    for (int i = 1; i <= n; i ++){
        if ( s[i] == '(' ) pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1] - 1;
    }

    for (int i = n; i >= 1; i --){
        if ( s[i] == ')' ) suf[i] = suf[i+1] + 1;
        else suf[i] = suf[i+1] - 1;
    }

    for (int i = 1; i <= n; i ++){
        h[i] = (1ll * h[i-1] * base % MOD + (s[i] == '(' ? 1 : 2)) % MOD;
        pw[i] = 1ll * pw[i-1] * base % MOD;
    }

    int ans = 0;
    for (int i = 0; i < n; i ++){
        if ( suf[n-i+1] == 0 && pre[n-i] == 0 ){
            int tmp = (1ll * get(n-i, n) * pw[n-i] % MOD + h[n-i]) % MOD;
            if ( !d[tmp] ){
                d[tmp] = 1;
                ans ++;
            }
        }
    }

    cout << ans;

    return 0;
}
