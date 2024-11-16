#include<bits/stdc++.h>
#define simon "fair"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e3 + 5;

int n;
string f[N];

void trau(){
    string s = "1";
    for (int i = 1; i <= n; i ++){
        string tmp = "";
        for (int j = 0; j < s.size(); j ++)
        if ( s[j] == '0' ) tmp += "10";
        else tmp += "01";
        s = tmp;
    }

    ll ans = 0;
    for (int i = 0; i < s.size() - 1; i ++)
        if ( s[i] == s[i+1] && s[i] == '0' )
            ans ++;
    cout << ans << '\n';
}

string add(string a, string b){
    string c = "";
    while (a.size() < b.size()) a = '0' + a;
    while  (b.size() < a.size()) b = '0' + b;
    int sum, carry = 0;

    for (int i = a.size() - 1; i >= 0; i --){
        int x = a[i] - '0', y = b[i] - '0';
        sum = x + y + carry;
        carry = sum / 10;
        c += char(sum % 10 + '0');
    }
    if ( carry ) c += '1';
    reverse(c.begin(), c.end());
    return c;
}

string sub(string a, string b){
    string c = "";
    while (a.size() < b.size()) a = '0' + a;
    while  (b.size() < a.size()) b = '0' + b;
    int sum, borrow = 0;

    for (int i = a.size() - 1; i >= 0; i --){
        int x = a[i] - '0';
        int y = b[i] - '0';
        sum = x - y - borrow;
        if ( sum < 0 ) sum += 10, borrow = 1;
        else borrow = 0;
        c += char(sum + '0');
    }
    reverse(c.begin(), c.end());
    while ( c.size() > 1 && c[0] == '0' ) c.erase(0, 1);
    return c;
}

void solve(){
    f[0] = f[1] = "0";
    for (int i = 2; i <= 1000; i ++){
        if ( !(i % 2) )
            f[i] = add(add(f[i-1], f[i-1]), "1");
        else
            f[i] = sub(add(f[i-1], f[i-1]), "1");
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    while ( cin >> n )
        cout << f[n] << '\n';

    return 0;
}
