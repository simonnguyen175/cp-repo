#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define l first
#define r second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e18 + 5;

int n;
struct segment{
    ll l, r, v;
    bool operator < (const segment &a) const{
        if ( r == a.r ) return v > a.v;
        return r < a.r;
    }
} seg[N];
ll s[N];
vector<pi> cont;
ll ans = 0;

int tknp(ll x){
    int lo = 1, hi = cont.size() - 1, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( cont[mid].r >= x ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("repset.inp", "r") ){
        freopen("repset.inp", "r", stdin);
        freopen("repset.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> seg[i].l >> seg[i].r >> seg[i].v;

    sort(seg + 1, seg + 1 + n);

//    for (int i = 1; i <= n; i ++)
//        cout << '(' << seg[i].l << ',' << seg[i].r << ',' << seg[i].v << ") "; cout << '\n';

    cont.pb({0, 0});
    cont.pb({seg[1].r-seg[1].v+1, seg[1].r});
    s[0] = 0, s[1] = seg[1].v;

    for (int i = 2; i <= n; i ++){
        int id = tknp(seg[i].l);

        if ( !id ){
            if ( seg[i].r - seg[i].v + 1 == cont.back().r + 1 ){
                ll nl = cont.back().l, nr = seg[i].r;
                cont.pop_back();
                cont.pb({nl, nr});
                s[cont.size()-1] = s[cont.size()-2] + nr - nl + 1;
            }
            else{
                ll nl = seg[i].r-seg[i].v+1, nr = seg[i].r;
                cont.pb({nl, nr});
                s[cont.size()-1] = s[cont.size()-2] + nr - nl + 1;
            }
            continue;
        }

        ll rem = seg[i].v - s[cont.size()-1] + s[id-1];
        if ( cont[id].l < seg[i].l ) rem += seg[i].l - cont[id].l;
//        cout << id << ' ' << rem << '\n';

        if ( rem <= 0 ) continue;

        rem --;
        ll nl, nr;
        nl = nr = seg[i].r;

        while ( cont.size() != 1 && rem ){
//            cout << "->" << nl << ' ' << rem << ' ';
            ll tmp = nl - cont.back().r - 1;
//            cout << tmp << ' ';
            if ( rem >= tmp ){
                rem -= tmp;
                nl = cont.back().l;
                cont.pop_back();
            }
            else{
                nl -= rem;
                rem = 0;
            }
        }
//        cout << '\n';
//        cout << rem << ' ' << nl << '\n';
        if ( rem ) nl -= rem;

        cont.pb({nl, nr});

        s[cont.size()-1] = s[cont.size()-2] + nr - nl + 1;

//        for (int i = 1; i < cont.size(); i ++)
//            cout << "( " << cont[i].l << ',' << cont[i].r << ") ";
//        cout << '\n';
    }

    for (int i = 1; i < cont.size(); i ++){
//        cout << "(" << cont[i].l << ',' << cont[i].r << ") ";
        ans += cont[i].r - cont[i].l + 1;
    }

    cout << ans;

    return 0;
}
