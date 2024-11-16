#include<bits/stdc++.h>
#define simon "median"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e3 + 5;

int n, a[N];
ll s = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s += a[i];
    }

    return 0;
}
