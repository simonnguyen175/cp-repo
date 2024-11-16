#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n;
ll k;
int a[N], bit[N], bit1[N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

// bit doan sau
void upd(int u, int v){
    for (; u <= n; u += u&-u) bit[u] += v;
}
int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u) res += bit[u];
    return res;
}

// bit doan truoc
void upd1(int u){
    for (; u >= 1; u -= u&-u) bit1[u] ++;
}
int get1(int u){
    int res = 0;
    for (; u <= n; u += u&-u) res += bit1[u];
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont.pb(a[i]);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    for (int i = 1; i <= n; i ++) a[i] = id(a[i]);

    ll cinv = 0;
    int r = 2;
    for (int i = n; i >= 2; i --){
        cinv += get(a[i]-1);
        upd(a[i], 1);
    }
    ll ans = 0;
    for (int l = 1; l < n; l ++){
        cinv += get(a[l]-1) + get1(a[l]+1);
        upd1(a[l]);
        while ( r <= n && ( r == l || cinv > k ) ){
            cinv -= get(a[r]-1) + get1(a[r]+1);
            upd(a[r], -1);
            r ++;
        }
        if ( r <= n ) ans += n-r+1;
    }
    cout << ans;

    return 0;
}
