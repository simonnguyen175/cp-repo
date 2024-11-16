#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e6 + 5;

int s, t;
int d[N];
vector<int> g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("divisors.inp", "r") ){
        freopen("divisors.inp", "r", stdin);
        freopen("divisors.out", "w", stdout);
    }

    cin >> s >> t;

    for (int i = 2; i <= t; i ++)
    for (int j = i * 2; j <= t; j += i)
        if ( j + i <= t )
            g[j].pb(j+i);

    memset(d, -1, sizeof d);
    d[s] = 0;

    for (int i = s; i <= t; i ++) if ( d[i] != -1 )
    for (int x : g[i])
        if ( d[x] == -1 ) d[x] = d[i] + 1;
        else d[x] = min(d[x], d[i]+1);

    cout << d[t];

    return 0;
}
