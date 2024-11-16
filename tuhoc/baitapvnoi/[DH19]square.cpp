#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;

int n;
ll ans=0;
int lpf[N], c[N];

void sieve(){
    lpf[1]=1;
    for (int i=3; i<=N; i+=2) lpf[i]=i;
    for (int i=2; i<=N; i+=2) lpf[i]=2;
    for (int i=3; i<=N; i+=2)
        for (int j=1; i*j <=N; j++){
                lpf[i*j]=min(lpf[i*j], i);
            }
}

int getMask(int x){
    int mask=1;
    while (x > 1){
        int p = lpf[x], f=0;
        do x/=p, f++; while ( p == lpf[x] );
        if ( f & 1 ) mask *=p;
    }
    return mask;
}

ll f(int x){ return 1LL * x * (x-1) / 2; }

void solve(){
    for (int a=1; a<=n; a++)
        ans += f(c[getMask(a)]++);
}

int main(){
    cin >> n;
    sieve();
    solve();
    cout << ans;
    return 0;
}
