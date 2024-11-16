#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e18;

int sub, n, k;
struct cre{
    ll fi, se, id;
    bool operator < (const cre &a) const {
        return fi < a.fi;
    }
} a[N];
multiset<pi> cont;
ll cost = 0, rem = 0, ans = oo, pos2 = 0;
int trace[N], cur[N];
vector<int> change;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("credit.inp", "r") ){
        freopen("credit.inp", "r", stdin);
        freopen("credit.out", "w", stdout);
    }

    cin >> sub >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].se >> a[i].fi, a[i].id = i;

    sort(a + 1, a + 1 + n);

    // chon toan bo 1
    for (int i = 1; i <= n; i ++) trace[i] = cur[i] = 1;
    for (int i = 1; i <= n; i ++)
        cont.insert({a[i].se, a[i].id}), rem += a[i].se;
    while ( cont.size() > k ){
        auto it = cont.rbegin(); rem -= (*it).fi;
        trace[(*it).se] = cur[(*it).se] = 0;
        cont.erase(*it);
    }
    if ( cont.size() == k ) ans = min(ans, rem), pos2 = 0;

    // chon cai 1 bang 2
    cont.erase({a[1].se, a[1].id}); rem -= a[1].se;
    cur[a[1].id] = 2; change.pb(a[1].id);
    while ( cont.size() > k - 2 ){
        auto it = cont.rbegin(); rem -= (*it).fi;
        cur[(*it).se] = 0; change.pb((*it).se);
        cont.erase(*it);
    }
    if ( cont.size() + 2 == k )
        if ( ans > a[1].fi + rem ){
            ans = a[1].fi + rem;
            for (auto x : change) trace[x] = cur[x];
            change.clear();
        }

//    for (int i = 1; i <= n; i ++)
//        cout << a[i].fi << ' ' << a[i].se << ' ' << a[i].id << '\n';
//    cout << '\n';
//
//    cout << ans << '\n';
//    for (int i = 1; i <= n; i ++)
//        cout << trace[i];
//    cout << '\n';

    //chon cai i bang 2
    for (int i = 2; i <= n; i ++){
        //cout << a[i].id << " : \n";

        if ( cont.find({a[i].se, a[i].id}) != cont.end() ){
            cont.erase({a[i].se, a[i].id}), rem -= a[i].se;
            cur[a[i].id] = 2; change.pb(a[i].id);
        }
        else
            cur[a[i].id] = 2; change.pb(a[i].id);

        cont.insert({a[i-1].fi - a[i-1].se, a[i-1].id + n});
        cost += a[i-1].se; rem += a[i-1].fi - a[i-1].se; cur[a[i-1].id] = 2;
        change.pb(a[i-1].id);

        while ( cont.size() > k - i - 1 ){
            auto it = cont.rbegin(); rem -= (*it).fi;
            if ( (*it).se <= n ) cur[(*it).se] = 0, change.pb((*it).se);
            else cur[(*it).se-n] = 1;
            cont.erase(cont.find(*it));
        }

        if ( cont.size() + i + 1 == k )
            if ( ans > cost + a[i].fi + rem ){
                ans = cost + a[i].fi + rem;
                for (auto x : change){
                    trace[x] = cur[x];
                }
                change.clear();
            }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i ++)
        cout << trace[i];

    return 0;
}
