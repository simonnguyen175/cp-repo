#include <bits/stdc++.h>
#define simon "ThreeGCD"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e6+5;
const ll oo=1e15;
const int MOD=123456789;

int X, Y, ans;

bool check(int x){
    if ( x >= X && x <= Y ) return true;
    else return false;
}

bool threeGcd(int x){
    int t;
    if ( X % x == 0 ) t=X/x;
    else t=X/x+1;

    if ( check(x*t) && check(x*(t+1)) && check(x*(t+2)) )
        return true;
    else return false;
}

int main(){
    FASTio
    if ( fopen ( simon".inp","r" ) ){
        freopen ( simon".inp", "r", stdin );
        freopen ( simon".out", "w", stdout );
    }
    cin >> X >> Y;
    for(int i=1; i<=Y; i++)
        if ( threeGcd(i) ) ans=i;
    cout << ans;
    return 0;
}



