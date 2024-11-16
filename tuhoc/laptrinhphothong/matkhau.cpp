#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
string s;

int main(){
    cin >> s ;
    s=' '+s ;
    long long res=1;
    long long temp=0;
    for (int i=1; i<=s.size(); i++){
        if (s[i]>='0' && s[i] <='9')
            temp=temp*10 + int(s[i]-'0');
        else{
            if ( temp > 0 )
                res=((res%MOD)*(temp%MOD)) % MOD;
            temp=0;
        }
    }
    if (temp > 0)
        res =( res*( temp % MOD ) ) % MOD;
    cout << res ;
}
