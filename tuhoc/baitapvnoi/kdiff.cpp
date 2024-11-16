#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 3e6 + 5;
const int oo = 1e9;

struct seq{
    int mx, mn;
};

int n, k, a[2*N];
seq st[2*N];
int res, mxx, mnn;
int f[2*N], g[2*N], ans;
bool check;

void update(int id, int l, int r){
    if ( l == r ){
        st[id].mx = a[l];
        st[id].mn = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid);
    update(id * 2 + 1, mid + 1, r);

    st[id].mx = max(st[id * 2].mx, st[id * 2 + 1].mx);
    st[id].mn = min(st[id * 2].mn, st[id * 2 + 1].mn);
}

void get_longest(int id, int l, int r, int u, int v){
    if ( l > v || r < u || l > r || !check ) return;

    int mid = (l + r)/2;

    if ( u <= l && r <= v ){
        int tmpmx = mxx, tmpmn = mnn;

        mxx = max(st[id].mx, mxx);
        mnn = min(st[id].mn, mnn);


        //cout <<l <<' '<<r <<' '<< mxx <<' '<<mnn<<'\n';


        if ( mxx - mnn <= k ){
            res = max(res, r - u + 1);
            return;
        }

        if ( l == r && mxx - mnn > k ) check = 0;

        mxx = tmpmx;
        mnn = tmpmn;


        get_longest(id * 2, l, mid, u, v);
        get_longest(id * 2 + 1, mid + 1, r, u, v);

        return;
    }

    get_longest(id * 2, l, mid, u, v);
    get_longest(id * 2 + 1, mid + 1, r, u, v);
}

int main(){
    FASTio
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    update(1, 1, n) ;

    /*
    for (int i = 1; i <= n; i ++)
        cout << '(' << st[i].mx <<' '<<st[i].mn<<')'<<' ';
    cout << '\n';
    */
    //cout << '\n';
    for (int i = 1; i <= n; i ++){
        res = 0;
        mnn = oo;
        mxx = -oo;
        check = 1;

        get_longest(1, 1, n, i, n);

        //cout << i + res - 1 <<' '<<res << '\n';
        f[i+res-1] = max(f[i + res - 1], res);

        g[i] = res;
    }

    for (int i = n; i >= 1; i --)
        if ( f[i + 1] > 0 && f[i] == 0 ){
            f[i] = f[i + 1] - 1;
        }


    for (int i = 2; i <= n; i ++)
        f[i] = max(f[i-1], f[i]);

    for (int i = 2; i <= n; i ++)
        ans = max(ans, f[i-1] + g[i]);

    cout << ans;

    return 0;
}
