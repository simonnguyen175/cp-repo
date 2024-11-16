#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;

int k, h, n;
ll p[N];
queue<ll> Q1, Q2;
unordered_map<ll, int> d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("ktree4.inp", "r") ){
        freopen("ktree4.inp", "r", stdin);
        freopen("ktree4.out", "w", stdout);
    }

    cin >> k >> h >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    sort(p + 1, p + 1 + n);
    n = unique(p + 1, p + 1 + n) - p - 1;

    if ( k == 1 ){
        cout << p[n] - p[1];
        return 0;
    }

    for (int i = n; i >= 1; i --)
        Q1.push(p[i]), d[p[i]] = 1;

    ll ans = 0;
    while ( Q1.size() + Q2.size() > 1 ){
        ans ++;

        if ( Q2.empty() ){
            ll u = Q1.front(); Q1.pop();
            ll pu = ( u + k - 2 ) / k;
            if ( pu && !d[pu] ) Q2.push(pu), d[pu] = 1;
            continue;
        }

        if ( Q1.front() > Q2.front() ){
            ll u = Q1.front(); Q1.pop();
            ll pu = ( u + k - 2 ) / k;
            if ( pu && !d[pu] ) Q2.push(pu), d[pu] = 1;
            continue;
        }
        else{
            ll u = Q2.front(); Q2.pop();
            ll pu = ( u + k - 2 ) / k;
            if ( pu && !d[pu] ) Q2.push(pu), d[pu] = 1;
            continue;
        }
    }

    cout << ans;

    return 0;
}
