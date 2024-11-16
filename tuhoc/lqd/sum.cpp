#include<bits/stdc++.h>
#define simon "sum"
using namespace std;

int n;
string ans;

bool check(string a, string b){
    int n = a.size(), m = b.size();
    if ( n > m ) return true;
    else{
        if ( n < m ) return false;
        for (int i=0; i<n; i++)
            if ( a[i] < b[i] ) return false;
    }
    return true;
}

void xuli(int cs, int k){
    string s = "";
    int tmp = 0;

    while ( k > 0 ){
        if ( tmp == 0 ){
            while ( tmp < n  ){
                tmp = tmp * 10 + cs;
                k--;
            }
        }
        else{
            tmp = tmp*10 + cs;
            k--;
        }

        s += (char) (tmp/n) + '0';
        tmp = tmp % n;
    }

    if ( ans == "" ){
        ans = s;
        return;
    }
    if ( check(ans, s) )
        ans = s;
}

int anal(int cs){
    int d = cs % n, k = 1;
    for (int i=1; i<=1000000 && d != 0; i++){
        d = ( d * 10 + cs ) % n;
        k ++;
    }
    if ( d != 0 ) return 0;
    return k;
}

void solve(int n){
    ans = "";
    bool check = 0;
    for (int i=1; i<=9; i++){
        int k = anal(i);
        if ( k > 0 ){
            check = 1;
            xuli(i, k);
            //cout << i <<' '<<k <<' '<< ans << '\n';
        }
    }
    if ( check ) cout << ans;
    else cout << -1;
}

int main(){
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    solve(n);
}
