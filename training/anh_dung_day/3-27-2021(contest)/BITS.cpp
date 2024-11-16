#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const string FILE_NAME = "";
const int N=1e5+5;

int t, n;
ll a[N];

void solve(int n){
    ll ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
            ans += (( a[i] | a[j]) ^ (a[i] & a[j]));
    cout << ans << '\n';
}

int main(){
    FASTio
    cin >> t;
    while( t-- ){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        solve(n);
    }
    return 0;
}
