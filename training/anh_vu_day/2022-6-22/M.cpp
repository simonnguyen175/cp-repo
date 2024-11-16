#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 5e4 + 5;
const ll oo = 1e15;

int n;
ll a[N], s[N];
map<ll, int> sub_gcd[N];
struct node{
    ll val, lazy;
} st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        st[id].val = s[l-1];
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].val = min(st[id*2].val, st[id*2+1].val);
}

void apply(int id, ll val){
//    cerr << "apply " << id << ' ' << val << '\n';
    st[id].val += val, st[id].lazy += val;
}

void down(int id){
    for (int i = 0; i <= 1; i ++)
        apply(id*2+i, st[id].lazy);
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, ll val){
//     cerr << l << ' ' << r << ' ' << u << ' ' << v << '\n';
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        apply(id, val);
        return;
    }
    int mid = l + r >> 1;
    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = min(st[id*2].val, st[id*2+1].val);
}

ll get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return st[id].val;
    int mid = l + r >> 1;
    down(id);
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];

    ll ans = 0;
    stack<int> stk;
    a[0] = oo, stk.push(0);
    build(1, 1, n);
    update(1, 1, n, 1, 1, a[1]);
    sub_gcd[1][a[1]] = 0;
    stk.push(1);

//    cerr << "---------\n";

    for (int i = 2; i <= n; i ++){
        sub_gcd[i][a[i]] = 0;
        for (auto it : sub_gcd[i-1]){
            ll ngcd = __gcd(it.fi, a[i]);
            sub_gcd[i][ngcd] = max(sub_gcd[i][ngcd], it.se+1);
        }

        while ( stk.size() && a[stk.top()] < a[i] ){
            int r = stk.top();
            stk.pop();
            int l = stk.top()+1;
            update(1, 1, n, l, r, -a[r]);
        }
        update(1, 1, n, stk.top()+1, i, a[i]);
        stk.push(i);

//        cerr << i << " : \n";
        for (auto it : sub_gcd[i]){
//            cerr << abs(it.fi) << ' ' << i-it.se << ' ' << i << ' ' << get(1, 1, n, i-it.se, i) << '\n';
            ans = max(ans, abs(it.fi) * ( s[i] - get(1, 1, n, i-it.se, i)));
        }
    }

    cout << ans;

    return 0;
}
