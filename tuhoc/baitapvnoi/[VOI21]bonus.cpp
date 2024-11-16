#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;

int n, m, t;
string c[N];
int p[N], cnt[N];
set<pair<int, int>> luck;
set<int> imp;
vector<int> lucknum[N], haveimp[N];

/*
namespace sub1{
    ll f[N];

    bool check(int i, int j){
        if ( luck.find({p[i], p[j]}) != luck.end()
            || luck.find({p[j], p[i]}) != luck.end() ) return true;
        else return false;
    }

    void solve(){
        for (int i = 1; i <= n; i ++) f[i] = p[i];

        for (int i = 1; i <= n; i ++)
            for (int j = 1; j < i; j ++){
                if ( (c[j].size() > c[i].size() && c[j].find(c[i]) == 0) || check(i, j) )
                    f[i] = max(f[i], f[j] + p[i]);
            }

        ll ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = max(ans, f[i]);

        cout << ans;
    }
}

namespace sub2{
    ll f[N];
    map<ll, ll> d;
    vector<ll> Hash[N];
    const int base = 31;
    const int MOD = 1e9 + 3;

    void makeHash(int i){
        ll tmph = 0;
        for (int j = 0; j < c[i].size(); j ++){
            tmph = (tmph * base + c[i][j] - 'a' + 1) % MOD;
            Hash[i].push_back(tmph);
        }
    }

    void solve(){
        for (int i = 1; i <= n; i ++) makeHash(i);
        ll ans = 0;
        for (int i = 1; i <= n; i ++){
            f[i] = d[Hash[i][c[i].size()-1]] + p[i];
            for (int j = 0; j < c[i].size()-1; j ++)
                d[Hash[i][j]] = max(d[Hash[i][j]], f[i]);
            ans = max(ans, f[i]);
        }
        cout << ans;
    }
}
*/

namespace sub3{
    ll f[N], g[N], b[N];
    map<ll, ll> d;
    vector<ll> Hash[N];
    const int base = 31;
    const int MOD = 1e9 + 3;

    void makeHash(int i){
        ll tmph = 0;
        for (int j = 0; j < c[i].size(); j ++){
            tmph = (tmph * base + c[i][j] - 'a' + 1) % MOD;
            Hash[i].push_back(tmph);
        }
    }

    bool check(int a, int b){
        if ( luck.find({a, b}) != luck.end() ||
             luck.find({b, a}) != luck.end() ) return true;
        else return false;
    }

    void solve(){
        for (int i = 1; i <= n; i ++) makeHash(i);

        ll ans = 0;
        for (int i = 1; i <= n; i ++){
            f[i] = max(d[Hash[i][c[i].size()-1]], b[p[i]]) + p[i];

            for (auto it : haveimp[p[i]])
                f[i] = max(f[i], g[it] + p[i]);

            for (int j = 0; j < c[i].size()-1; j ++)
                d[Hash[i][j]] = max(d[Hash[i][j]], f[i]);

            if ( imp.find(p[i]) != imp.end() ) g[p[i]] = max(g[p[i]], f[i]);
            else
            for (auto it : lucknum[p[i]]){
                b[it] = max(b[it], f[i]);
            }

            ans = max(ans, f[i]);
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> c[i] >> p[i];

    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        luck.insert({u, v});
        lucknum[u].push_back(v);
        lucknum[v].push_back(u);
        cnt[u] ++, cnt[v] ++;
    }

    t = sqrt(m);
    for (auto it = luck.begin(); it != luck.end(); it ++){
        if ( cnt[(*it).first] >= t ) imp.insert((*it).first);
        if ( cnt[(*it).second] >= t ) imp.insert((*it).second);
    }

    for (auto it = imp.begin(); it != imp.end(); it ++)
        for (auto v : lucknum[*it])
            haveimp[v].push_back(*it);

    /*
    if ( n <= 100 ) sub1::solve();
    else sub2::solve();
    */
    sub3::solve();

    return 0;
}
