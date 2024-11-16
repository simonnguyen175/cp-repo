#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, res, ans[N];
struct score{
    int first;
    int second;
    int id;
} a[N];
int st[4 * N];


bool compare(score a, score b){
    if ( a.first < b.first ) return true;
    else
        if ( a.first > b.first ) return false;
            else return a.second < b.second;
}

void update(int id, int l, int r, int i){
    if ( l > i || r < i ) return;

    if ( l == i && r == i){
        st[id] ++;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, i);
    update(id * 2 + 1, mid + 1, r, i);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, compare);

    for (int i = 1; i <= n; i ++){
        if ( a[i].first == a[i-1].first && a[i].second == a[i-1].second){
            ans[a[i].id] = res;
            update(1, 1, 100000, a[i].se);
            continue;
        }
        res = get(1, 1, 100000, 0, a[i].se);
        update(1, 1, 100000, a[i].se);
        ans[a[i].id] = res;
    }

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << '\n';

    return 0;
}
