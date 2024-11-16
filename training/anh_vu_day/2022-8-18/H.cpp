#include<bits/stdc++.h>
#define eb emplace_back
#define pb push_back
#define ll long long
#define BIT(x,k) ((x>>k)&1)
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
const int oo = 2e9;

int n, sz;
int a[N], trie[N*30][2], cnt[N*30], idx[N*30], Par[N];
vector<int> s[N];

void Insert(int x, int id){
    int cur = 0;
    for (int i = 29; i >= 0; i --){
        int t = BIT(x, i);
        if ( trie[cur][t] == -1 ) trie[cur][t] = ++sz;
        cur = trie[cur][t];
        cnt[cur] ++;
    }
    idx[cur] = id;
}

void Erase(int x){
    int cur = 0;
    for (int i = 29; i >= 0; i --){
        int t = BIT(x, i);
        cur = trie[cur][t];
        cnt[cur] --;
    }
}

int Get(int x){
    int cur = 0;
    for (int i = 29; i >= 0; i --){
        int t = BIT(x, i);
        if ( trie[cur][t] == -1 || !cnt[trie[cur][t]] ) t ^= 1;
        cur = trie[cur][t];
    }
    return idx[cur];
}

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( s[u].size() < s[v].size() ) swap(u, v);
        Par[v] = u;
        for (int x : s[v]) s[u].pb(x);
        s[v].clear();
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // init
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+1+n);
    n = unique(a+1, a+1+n)-a-1;
    memset(trie, -1, sizeof trie);
    for (int i = 1; i <= n; i ++)
        Insert(a[i], i);
    for (int i = 1; i <= n; i ++)
        Par[i] = i, s[i].pb(i);

    // boruvka
    int ncomp = n;
    ll ans = 0;
    while ( ncomp > 1 ){
        vector<pair<pi, int>> Add;

        for (int i = 1; i <= n; i ++) if ( s[i].size() ){
            for (int x : s[i]) Erase(a[x]);

            pi res = {oo, 0};
            for (int x : s[i]){
                int y = Get(a[x]);
                if ( res.fi > (a[x]^a[y]) )
                    res = {a[x]^a[y], y};
            }

            Add.pb({{i, res.se}, res.fi});

            for (int x : s[i]) Insert(a[x], x);
        }

        for (auto it : Add)
            if ( Join(it.fi.fi, it.fi.se) )
                ans += it.se, ncomp --;
    }

    cout << ans;

    return 0;
}
