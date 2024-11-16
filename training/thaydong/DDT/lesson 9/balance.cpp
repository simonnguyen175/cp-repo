#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[50];

namespace sub1{
    void solve(){
        int tt[50];
        for (int i = 1; i <= n; i ++)
        tt[i] = i;

        long long ans = 0;

        do{
            for (int t = 0; t < (1<<n); t ++){
                bool flag = 1;
                long long sl = 0, sr = 0;

                for (int i = 1; i <= n; i ++){
                    if ( t & (1<<(i-1)) ) sr += a[tt[i]];
                    else sl += a[tt[i]];
                    if ( sl > sr ){
                        flag = 0;
                        break;
                    }
                }
                if ( flag ) ans ++;
            }

        }while (next_permutation(tt + 1, tt + 1 + n));

        cout << ans << '\n';
    }
}

namespace sub2{
    ll f[5000000];
    int mu3[15];

    ll calc(int t, int t2, ll s1, ll s2){
        if ( f[t] ) return f[t];
        if ( t2 == (1<<n)-1 ) return 1;
        ll cnt = 0;
        for (int i = 0; i < n; i ++){
            if ( ( t2 & (1<<i) ) == 0 ){
                if ( s1 + a[i+1] <= s2 )
                    cnt += calc(t + mu3[i], t2|(1<<i), s1 + a[i+1], s2);

                cnt += calc(t + 2*mu3[i], t2|(1<<i), s1, s2 + a[i+1]);
            }
        }
        f[t] = cnt;
        return cnt;
    }

    void solve(){
        mu3[0] = 1;
        for (int i = 1; i <= 15; i ++)
            mu3[i] = mu3[i-1] * 3;

        cout << calc(0, 0, 0, 0) << '\n';
    }
}

namespace sub3{
    string add(string a, string b){
        while (a.size() < b.size()) a='0'+a;
        while  (b.size() < a.size()) b='0'+b;

        int Lena = a.size(), Lenb = b.size();

        string c = "";
        int x, y, sum, carry = 0;
        for (int i = Lena - 1; i >= 0; i--){
            x = a[i]-'0';
            y = b[i]-'0';
            sum = x + y + carry;
            carry = sum / 10;
            c = char(sum % 10 +'0') + c ;
        }

        if ( carry > 0 ) c='1'+c;
        return c;
    }

    string mul(string a, int b){
        string tmp = a;
        for (int i = 1; i < b; i ++){
            a = add(a, tmp);
        }
        return a;
    }

    void solve(){
        string res = "1";
        for (int i = 1, x = 1; i <= n; i ++, x += 2){
            res = mul(res, x);
        }
        cout << res << '\n';
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    if ( n <= 7 ) {sub1::solve(); return 0;}

    if ( n <= 14 ) {sub2::solve(); return 0;}

    sub3::solve();

    return 0;
}
