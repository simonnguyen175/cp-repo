#include<bits/stdc++.h>
#define simon "dweight"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define llll pair<long long, long long>
using namespace std;
const int N = 3e2 + 5;

int t, n;
pair<ll, ll> a[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    for (int q=1; q<=t; q++){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i].first >> a[i].second;

        set<llll> point;

        for (int i=1; i<n; i++)
            for (int j=i+1; j<=n; j++){
                if ( a[i].first == a[j].first ) continue;
                else{
                    ll x = a[j].first - a[i].first;
                    ll y = a[i].second - a[j].second ;
                    ll d = __gcd(x, y);
                    x /= d; y /= d;
                    if ( ( x * y ) <= 0  ) continue;
                    point.insert({x, y});
                }
            }

        cout << point.size() + 1 << '\n';

    }

    return 0;
}
