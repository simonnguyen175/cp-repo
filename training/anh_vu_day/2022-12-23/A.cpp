#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, nn;
pi a[N];
vector<int> cont;
int nxt[2*N][19];

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

int get(int l, int r){
    int res = 0;
    for (int i = 18; i >= 0; i --)
        if ( nxt[l][i] <= r + 1 ){
            res += (1<<i), l = nxt[l][i];
        }
    return res;
}

bool check(int i, int l, int r){
    return get(l, a[i].fi - 1) + get(a[i].se + 1, r) + 1 == get(l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        cont.pb(a[i].fi);
        cont.pb(a[i].se);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    nn = cont.size();

    for (int i = 1; i <= nn + 2; i ++) nxt[i][0] = nn + 2;
    for (int i = 1; i <= n; i ++){
        a[i].fi = id(a[i].fi);
        a[i].se = id(a[i].se);
        nxt[a[i].fi][0] = min(nxt[a[i].fi][0], a[i].se+1);
    }

    for (int i = nn; i >= 1; i --)
        nxt[i][0] = min(nxt[i+1][0], nxt[i][0]);

    for (int j = 1; j <= 18; j ++)
    for (int i = 1; i <= nn+2; i ++)
        nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    vector<int> ans;
    set<pi> ranges;
    ranges.insert({1, nn});
    for (int i = 1; i <= n; i ++){
        if ( !ranges.size() ) break;
        auto it = ranges.lower_bound({a[i].fi + 1, 0});
        it --;

        int lef = it->fi, rig = it->se;
        if ( lef <= a[i].fi && rig >= a[i].se && check(i, lef, rig) ){
            ans.pb(i);
            ranges.erase(it);
            if ( lef <= a[i].fi-1 ) ranges.insert({lef, a[i].fi-1});
            if ( a[i].se+1 <= rig ) ranges.insert({a[i].se+1, rig});
        }

        else continue;
    }

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';

    return 0;
}
