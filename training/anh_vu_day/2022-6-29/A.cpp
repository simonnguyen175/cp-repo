#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, q, k;
int a[N];
struct query{
    int l, r, id;
} que[N];
ll ans[N], res = 0;
int d[N*10];

void add(int x){
    res -= 1LL * d[x] * d[x] * x;
    d[x] ++;
    res += 1LL * d[x] * d[x] * x;
}

void rem(int x){
    res -= 1LL * d[x] * d[x] * x;
    d[x] --;
    res += 1LL * d[x] * d[x] * x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    k = sqrt(n);
    for (int i = 1; i <= q; i ++)
        cin >> que[i].l >> que[i].r, que[i].id = i;
    sort(que+1, que+1+q, [&](query x, query y){
        return ( x.l/k != y.l/k ? x.l < y.l : x.r < y.r );
    });


    int l = 0, r = 0;
    for (int i = 1; i <= q; i ++){
        if ( l >= que[i].l )
            for (int j = l-1; j >= que[i].l; j --) add(a[j]);
        else
            for (int j = l; j < que[i].l; j ++) rem(a[j]);

        if ( r <= que[i].r )
            for (int j = r+1; j <= que[i].r; j ++) add(a[j]);
        else
            for (int j = r; j > que[i].r; j --) rem(a[j]);

        ans[que[i].id] = res;

        l = que[i].l, r = que[i].r;
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
