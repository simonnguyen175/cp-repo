#include<bits/stdc++.h>
#define fi first
#define se second
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5 + 5;

struct node{
    long long val, sl;
};

int n;
pair<int, int> a[N];
node bit[N];

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void update(int idx, int v){
    while ( idx <= n ){
        bit[idx].val += v;
        bit[idx].sl ++;
        idx += idx & (-idx);
    }
}

node get(int u){
    node res; res.sl = res.val = 0;
    int idx = u;
    while ( idx > 0 ){
        res.val += bit[idx].val;
        res.sl += bit[idx].sl;
        idx -= idx & (-idx);
    }
    return res;
}

int main(){
    FASTio
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].se;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi;

    sort(a + 1, a + 1 + n, cmp);

    int cnt = 1, tmp = a[1].se; a[1].se = 1;
    for (int i = 2; i <= n; i ++)
        if ( a[i].se > tmp ){
            a[i].se = ++cnt;
            tmp = a[i].se;
        }
        else a[i].se = a[i-1].se;

    memset(bit, 0, sizeof bit);
    sort(a + 1,  a + 1 + n);


    long long  ans = 0;
    for (int i = 1; i <= n; i ++){
        node tmp = get(a[i].se);
        ans += tmp.sl * a[i].se - tmp.val;
        update(a[i].se, a[i].se);
    }

    cout << ans;

    return 0;
}
