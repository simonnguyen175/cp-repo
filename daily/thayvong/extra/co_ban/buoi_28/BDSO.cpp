#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "BDSO"
using namespace std;

ll n, k, ans;

ll findE(ll x){
    ll tmp=x;
    string s="";
    while ( x > 0 ){
        int k=x%10;
        s += (k+'0');
        x /= 10;
    }
    sort(s.begin(), s.end());
    ll g=0, f=0;
    for (int i=0; i<s.size(); i++)
        f=f*10+(s[i]-'0');
    for (int i=s.size()-1; i>=0; i--)
        g=g*10+(s[i]-'0');
    return g-f;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        k=findE(k);
    cout << k;
    return 0;
}
