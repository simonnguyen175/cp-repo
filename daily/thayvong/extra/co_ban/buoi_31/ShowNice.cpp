#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "ShowNice"
using namespace std;
const int N = 1e5 + 5;

int n, a[N], ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    sort(a+1, a+1+n);
    int tmp = 1;
    for (int i = 2; i <= n; i ++){
        if ( a[i] == a[i-1] ) tmp ++;
        else{
            if ( tmp < a[i-1] ) ans += tmp;
            if ( tmp > a[i-1] ) ans += tmp - a[i-1];
            tmp = 1;
        }
    }
    if ( tmp < a[n] ) ans += tmp;
    if ( tmp > a[n] ) ans += tmp - a[n];

    cout << ans;
    return 0;
}
