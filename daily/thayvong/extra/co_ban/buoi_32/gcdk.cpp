#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, k;
long long a[N], st[N];

void update(int id, int l, int r){
    if ( l == r ){
        st[id] = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);

    st[id] = __gcd(st[id * 2], st[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return __gcd(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    freopen("gcdk.inp","r",stdin);
	freopen("gcdk.out","w",stdout);
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];


    update(1, 1, n);

    long long ans = 0;

    for (int i = k; i <= n; i ++)
        ans = max (ans, get(1, 1, n, i - k + 1, i));

    cout << ans;

    return 0;
}
