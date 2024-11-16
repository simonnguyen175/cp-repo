#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 6e4 + 5;

int n;
pair<int, int> a[N];
int st[4 * N];
long long ans = 0;

void update(int id, int l, int r, int u, int w){
    if ( r < u || u < l ) return;

    if ( l == r ){
        st[id] = w;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
    if ( r < u || l > v ) return 0;

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
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(a + 1, a + 1 + n);


    for (int i = 1; i <= n; i ++)
        update(1, 1, n, i, 1);

    int pos = 1;

    for (int i = 1; i <= n; i ++){
        for (pos; pos < i; pos ++)
            update(1, 1, n, a[pos].se, 0);
        ans += get(1, 1, n, 1, a[i].second - 1);
    }

    cout << ans;

    return 0;
}
