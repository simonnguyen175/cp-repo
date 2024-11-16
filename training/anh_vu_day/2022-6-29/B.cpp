#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
ll a[N], add[N], sum[N];
struct Set{
    int sz;
    vector<int> v;
} s[N];
vector<pi> g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= m; i ++){
        cin >> s[i].sz;
        s[i].v.resize(s[i].sz+1);
        for (int j = 1; j <= s[i].sz; j ++)
            cin >> s[i].v[j];
    }

    for (int i = 1; i <+ m; i ++) if ( s[i].sz > sqrt(n) ){
        for (int j = 1; j <= n; j ++) d[j] = 0;
        for (int j = 1; j <= s[i].sz; j ++) d[s[i].v[j]] = 1;

        for (int j = 1, cnt = 0; j <= m; j ++){
            for (int k = 1; k <= s[j].sz; k ++)
                cnt += d[s[j].v[k]];
            g[j].pb({i, cnt});
        }
    }

    char type;
    int k, x;
    while ( q -- ){
        cin >> type;
        if ( type == '?' ){
            cin >> k;
            if ( s[k].sz <= sqrt(n) ){
                ll res = 0;
                for (int i = 1; i < s[k].sz; i ++)
                    res += a[s[k].v[i]];
                for (auto it : g[k])
                    res += 1LL * add[it.fi] * it.se;
                cout << res << '\n';
            }
            else{
                cout << add[k] * s[k].sz + sum[k]<< '\n';
            }
        }
        else{
            cin >> k >> x;
            if ( s[k].sz <= sqrt(n) ){
                for (int i = 1; i <= s[k].sz; i ++)
                    a[s[k].v[i]] += x;
                for (auto it : g[k])
                    sum[it.fi] += 1LL * x * it.se;
            }
            else{
                add[k] += x;
                for (auto it : g[k])
                    sum[it.fi] += 1LL * x * it.se;
            }
        }
    }
}
