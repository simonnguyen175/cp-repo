#include <bits/stdc++.h>
#define simon "EP"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
using namespace std;
const int N=1e6+1;

int T;
int present[N];

int tts(int x){
    if ( x == 1 ) return 1;
    int res=1;
    for (int i=2; i<=sqrt(x); i++)
        if ( x % i == 0 ){
            while ( x % i == 0 ) x/=i;
            res*=i;
        }
    if ( x != 1 ) res*=x;
    return res;
}

void solve(int a, int b){
    for (int i=1; i<=b; i++) present[i]=0;
    int res=0;
    for (int i=a; i<=b; i++)
        present[tts(i)]++;
    for (int i=2; i<=b; i++)
        res += present[i]*(present[i]-1)/2;
    cout << res <<'\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    memset(present, 1, sizeof present);
    cin >> T;
    for (int i=1; i<=T; i++){
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
