#include <bits/stdc++.h>
#define simon "spass"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=1e6+1;
const int oo=1e18;

string s;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> s;
    int n=s.size();
    s=' '+s;
    int low=0, up=0, num=0, ans=INT_MAX;
    int i=1, id=1;
    while ( i <= n ){
        if ( s[i] >= 'a' && s[i] <= 'z' ) low++;
        if ( s[i] >= 'A' && s[i] <= 'Z' ) up++;
        if ( s[i] >= '0' && s[i] <= '9' ) num++;

        while ( low > 1 && up > 1 && num > 1 && i-id > 6 ){
            if ( s[id] >= 'a' && s[id] <= 'z' ) low--;
            if ( s[id] >= 'A' && s[id] <= 'Z' ) up--;
            if ( s[id] >= '0' && s[id] <= '9' ) num--;
            id++;
        }

        if ( low >= 1 && up >= 1 && num >= 1 ) ans=min(ans, i-id);
        i++;
    }
    cout << ans;
    return 0;
}
