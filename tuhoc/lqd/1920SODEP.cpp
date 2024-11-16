#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll s;

ll tcs(ll x){
    ll res = 0;
    while ( x > 0 ){
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main(){
    cin >> s;
    s = tcs(s);
    while ( s > 9 ){
        s = tcs(s);
    }
    cout << s;
    return 0;
}
