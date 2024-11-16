#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;
const int MXA = 5e4 + 5;

int n, Q;
int a[N];
pi q[N];

void upd(int u){
    for (; u > 0; u -= u&-u)
        bit[u] ++;
}

int get(int u){
    int res = 0;
    for (; u <= MXA-5; u += u&-u)
        res += bit[u];
    return res;
}

void fakeupd(int x, int y, int val, int t){
    if ( !t )
        for (; x > 0; x -= x&-x)
            node0[x].pb(y);
    else
        for (; x <= MXA-5; x += x&-x)
            node1[x].pb(y);
}

void fakeget(int x, int y, int t){
    if ( !t )
        for (; x <= MXA-5; x += x&-x)
            node0[x].pb(y);
    else
        for (; x > 0; x -= x&-x)
            node1[x].pb(y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        ans += get(a[i]+1);
        upd(a[i], 1);
    }


    for (int i = 1; i <= n; i ++) b[i] = a[i];

    cin >> Q;
    for (int i = 1, x, y; i <= Q; i ++){
        cin >> x >> y;
        q[i] = {x, y};

        fakeget(a[x]+1, x-1, 0);
        fakeget(a[x]-1, x+1, 1);
        fakeupd(a[x], x, -1, 0);
        fakeupd(a[x], x, -1, 1);

        a[x] = y;

        fakeget(a[x]+1, x-1, 0);
        fakeget(a[x]-1, x+1, 1);
        fakeupd(a[x], x, 1, 0);
        fakeupd(a[x], x, 1, 1);
    }

    for (int i = 1; i <= MXA-5; i ++){
        sort(node[i].begin(), node[i].end());
        node[i].erase(unique(node[i].begin(), node[i].end()), node[i].end());
    }

    for (int i = 1; i <= Q; i ++){
        int x = q[i].fi, y = q[i].se;

        get1(b[x]+1, x-1, 0);
        get1(b[x]-1, x+1, 1);
        upd1(b[x], x, -1, 0);
        upd1(b[x], x, -1, 1);

        b[x] = y;

        get1(b[x]+1, x-1, 0);
        get1(b[x]-1, x+1, 1);
        upd1(b[x], x, 1, 0);
        upd1(b[x], x, 1, 1);
    }

    return 0;
}
