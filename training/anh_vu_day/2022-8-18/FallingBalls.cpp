#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
struct line{
    int l, r, x;
    bool operator < (const line &a) const{
        return x < a.x;
    }
} a[N];
set<line> cont;
int ans[N];

void anal(int l, int r, int x){
    if ( l > r ) return;
    auto it = cont.lower_bound({0, 0, l});
    if ( it == cont.end() || it->x > r ) return;

    int lo = it->l, hi = it->r;
    while ( it != cont.end() && it->x <= r ){
//        cout << it->l << ' ' << it->r << '\n';
        lo = min(lo, it->l);
        hi = max(hi, it->r);
        it = cont.erase(it);
    }
//    cout << "=> " << lo << ' ' << hi << " --> " << x << '\n';
    cont.insert({lo, hi, x});
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l >> a[i].r >> a[i].x;
    sort(a+1, a+1+n);
    for (int i = 0; i <= 1e5; i ++) cont.insert({i, i, i});
    for (int i = n; i >= 1; i --){
        int l = a[i].l, r = a[i].r;
        int mid = l + r >> 1;
        anal(l, mid, l);
        anal(mid+1, r, r);
    }

    for (auto it : cont)
    for (int i = it.l; i <= it.r; i ++)
        ans[i] = it.x;

    for (int i = 1, x; i <= m; i ++){
        cin >> x;
        cout << ans[x] << '\n';
    }

    return 0;
}
