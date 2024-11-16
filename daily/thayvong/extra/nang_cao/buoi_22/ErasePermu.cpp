#include<bits/stdc++.h>
#define ll long long
#define simon "ErasePermu"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e5+5;

int n, a[N], b[N], ans;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    ans=n+1;
    int x=0, m=0;
    for (int i=1; i<=n; i++){
        if ( a[i] <= 0 ){
            x++;
            continue;
        }
        if ( i > 1 && a[i] == a[i-1] ){
            x++;
            continue;
        }
        b[++m]=a[i];
    }

    for (int i=m; i>=1; i--){
        ans=min(ans, b[i]-i+x);
        x++;
    }
    cout << ans;
    return 0;
}
