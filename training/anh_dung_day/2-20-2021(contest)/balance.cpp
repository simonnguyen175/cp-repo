#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, M, a[100], b[100], ans=0;

void xuli(){
    ll l=0, r=0;
    for (int i=1; i<=n; i++){
        if (b[i] == 0) l+=a[i];
        if (b[i] == 1) r+=a[i];
    }
    if ( l + M == r ) ans++;
}

void gen(int i){
    for (int j=0; j<=2; j++){
        b[i]=j;
        if ( i == n ) xuli();
        else gen(i+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> M;
    for (int i=1; i<=n; i++) cin >> a[i];
    gen(1);
    cout << ans;
}
