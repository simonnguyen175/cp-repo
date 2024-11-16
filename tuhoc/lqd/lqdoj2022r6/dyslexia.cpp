#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;

const char B64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int position[256];
void initBase64(){
    for (int i = 0; i < 64; i++)
        position[B64[i]] = i;
}

int n;
string S64;
char S[N];
void b64Conversion(const string &s){
    int ptr = 0;
    for (char c: s){
        int x = position[c];
        for (int i = 0; i < 6; i++){
            S[ptr++] = (x & 1) + '0';
            x >>= 1;
        }
    }
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

namespace sub2{
    void solve(){
        int ans = 0;

        for (int i = 0; i < n; i ++){
            int c0 = 0, c1 = 0;
            for (int j = i; j < n; j ++){
                if ( S[j] == '0' ) c0 ++;
                else c1 ++;

                if ( c0 && c1 ) ans = add(ans, mul(c0, c1));
                else if ( c0 ) ans = add(ans, mul(c0, c0));
                else ans = add(ans, mul(c1, c1));
            }
        }

        cout << ans;
    }
}

namespace sub3{
    void solve(){
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = add(ans, mul(n-i+1, mul(i, i)));
        cout << ans;
    }
}

namespace sub4{
    int sum(int r){
        return ((r+1)*r/2)%MOD;
    }

    void solve(){
        int pos;
        for (int i = 0; i < n-1; i ++) if ( S[i] != S[i+1] ){
            pos = i;
            break;
        }

        int ans = 0;
        for (int i = 1; i <= pos+1; i ++)
            ans = add(ans, mul(pos+1-i+1, mul(i, i)));
        for (int i = 1; i <= n-1-pos; i ++)
            ans = add(ans, mul(n-1-pos-i+1, mul(i, i)));
        ans = add(ans, mul(sum(pos+1), sum(n-1-pos)));

        cout << ans;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("dyslexia.inp", "r", stdin);
    freopen("dyslexia.out", "w", stdout);

    cin >> n >> S64;
    initBase64(); b64Conversion(S64);

//    for (int i = 0; i < n; i ++)
//        cout << S[i];
//    cout << '\n';

    if ( n <= 1e3 ) { sub2::solve(); return 0; }

    bool ck3 = 1;
    for (int i = 0; i < n-1; i ++)
        ck3 &= ( S[i] == S[i+1] );
    if ( ck3 ) { sub3::solve(); return 0; }

    sub4::solve();

    return 0;
}
