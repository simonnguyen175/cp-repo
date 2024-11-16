#include<bits/stdc++.h>
#define simon "credit"
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 6e5 + 5;
const ll oo = 1e18;

int sub, n, k;
struct subj{
    int fi, se, id;
} a[N];
struct node{
    ll cnt, sum;
} st[4*N];
vector<int> cont;
int res[N];

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void update(int pos, int w, int add){
    int id = 1, l = 1, r = cont.size();
    while ( l <= r ){
        st[id].sum += w * add;
        st[id].cnt += add;
        if ( l == r ) break;
        int mid = l + r >> 1;
        if ( pos <= mid )
            r = mid, id *= 2;
        else l = mid + 1, id = id*2+1;
    }
}

ll get(int k){
    int id = 1, l = 1, r = cont.size(), d = k;
    ll res = 0;
    if ( st[1].cnt < k ) return oo;

    while ( l <= r ){
        if ( l == r ){
            if ( st[id].cnt ) res += st[id].sum/st[id].cnt * d;
            d = 0;
            break;
        }
        int mid = l + r >> 1;
        if ( st[id*2].cnt >= d ) id *= 2, r = mid;
        else{
            d -= st[id*2].cnt, res += st[id*2].sum;
            l = mid + 1, id = id * 2 + 1;
        }
    }
    if ( d ) return oo;
    else return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    // init
    cin >> sub >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
        cont.pb(a[i].fi);
        cont.pb(a[i].se-a[i].fi);
    }
    sort(a+1, a+1+n, [&](subj x, subj y){
        return x.se < y.se;
    });
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    // solve
    for (int i = 1; i <= n; i ++)
        update(id(a[i].fi), a[i].fi, 1);
    ll ans = get(k);
    ll pre = 0, pos = 0;
    for (int i = 1; i <= n; i ++) if ( k > i - 1 ){
        update(id(a[i].fi), a[i].fi, -1);
        ll tmp = min(ans, pre + a[i].se + get(k-i-1));
        if ( ans > tmp ) pos = i, ans = tmp;
        update(id(a[i].se-a[i].fi), a[i].se-a[i].fi, 1);
        pre += a[i].fi;
    }

    // trace
    cout << ans << '\n';
    if ( !pos ){
        sort(a+1, a+1+n, [&](subj x, subj y){
            return x.fi < y.fi;
        });
        for (int i = 1; i <= k; i ++) res[a[i].id] = 1;
        for (int i = 1; i <= n; i ++) cout << res[i];
        return 0;
    }
    vector<pi> tmp;
    for (int i = 1; i < pos; i ++){
        res[a[i].id] = 1;
        tmp.pb({a[i].se-a[i].fi,a[i].id});
    }
    res[a[pos].id] = 2;
    for (int i = pos+1; i <= n; i ++)
        tmp.pb({a[i].fi, a[i].id});
    sort(tmp.begin(), tmp.end());
    if ( k-pos-1 >= 0 )
        for (int i = 0; i < k-pos-1; i ++)
            res[tmp[i].se] ++;
    for (int i = 1; i <= n; i ++) cout << res[i];

    return 0;
}
