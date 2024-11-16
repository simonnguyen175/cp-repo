#include<bits/stdc++.h>
#define simon "rtri"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define x first
#define y second
using namespace std;
const int N = 3e5 + 5;

int n;
ll ans = 0;
pair<int, int> a[N];
unordered_map<int, ll> dx, dy;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        dx[a[i].x] ++; dy[a[i].y] ++;
    }

    for (int i = 1; i <= n; i ++)
        ans += ( dx[a[i].x] - 1 ) * ( dy[a[i].y] - 1 );

    cout << ans;

    return 0;
}
