#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<pi, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9 + 7;

int n, m, k, a, b, x, y;
vector<pi> Set[N], st[4*N];
vector<pii> cont;
multiset<int> mxR;
int mnR[N];

void build(int id, int l, int r){
//    cout << "build " << l << ' ' << r << " : \n";

    cont.clear(); mxR.clear();
    for (int i = l; i <= r; i ++){
        for (auto x : Set[i])
            cont.pb({x, i});
        mnR[i] = oo;
    }
    sort(cont.begin(), cont.end(), greater<pii>());

//    for (auto x : cont){
//        cout << "(" << x.fi.fi << ',' << x.fi.se << ',' << x.se << ") ";
//    }
//    cout << '\n';

    for (auto x : cont){
        auto it = mxR.find(mnR[x.se]);
        if ( it != mxR.end() ) mxR.erase(it);

        mnR[x.se] = min(mnR[x.se], x.fi.se);
        mxR.insert(mnR[x.se]);

        if ( mxR.size() == r-l+1 ) st[id].pb({x.fi.fi, *mxR.rbegin()});
    }
    reverse(st[id].begin(), st[id].end());
    st[id].pb({oo, oo});

//    for (auto x : st[id])
//        cout << "(" << x.fi << ',' << x.se << ") ";
//    cout << '\n';

    if ( l == r ) return;

    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}

bool get(int id, int l, int r){
    if ( a > r || b < l ) return 1;
    if ( a <= l && r <= b ){
        auto it = lower_bound(st[id].begin(), st[id].end(), pi(x, -1));
        return ( it->se <= y );
    }
    int mid = l + r >> 1;
    return ( get(id*2, l, mid) & get(id*2+1, mid+1, r) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++){
        int l, r, p;
        cin >> l >> r >> p;
        Set[p].pb({l, r});
    }

//    for (int i = 1; i <= n; i ++){
//        cout << "Set "<< i << " : \n";
//        for (auto x : Set[i])
//            cout << "(" << x.fi << ',' << x.se << ") ";
//        cout << '\n';
//    }

    build(1, 1, n);

    for (int i = 1; i <= m; i ++){
        cin >> a >> b >> x >> y;
        cout << ( get(1, 1, n) ? "yes" : "no" );
        cout << endl;
    }

    return 0;
}
