#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], d[N], Par[N], Rank[N];
ll ans = 0;

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        Par[v] = u;
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( d[a[i]] )
            if ( Join(i, d[a[i]]) ) ans += 123456 - a[i];
        d[a[i]] = i;
    }

    for (int i = N-5; i >= 1; i --){
        int pre = 0;
        for (int j = i; j <= N-5; j += i) if ( d[j] ){
            if ( pre ){
                if ( Join(pre, d[j]))
                    ans += 123456 - i;
            }
            else pre = d[j];
        }
    }

    cout << ans;

    return 0;
}
