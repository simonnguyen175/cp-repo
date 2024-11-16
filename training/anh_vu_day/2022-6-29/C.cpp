#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int oo = 1e9;

int n, m, k;
int a[N], lef[N], rig[N], ans[N];
struct query{
    int l, r, id;
} q[N];

int block(int x){
    return ( (x%k)>0 ? x/k+1 : x/k );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    k = sqrt(n);

    vector<int> cont;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], cont.pb(a[i]);
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    for (int i = 1; i <= n; i ++)
        a[i] = upper_bound(cont.begin(), cont.end(), a[i]) - cont.begin();


    for (int i = 1; i <= m; i ++)
        cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(q+1, q+1+m, [&](query a, query b){
        return ( block(a.l) != block(b.l) ? a.l < b.l : a.r < b.r );
    });

    for (int i = 1; i <= m; i ++) ans[i] = oo;

    for (int i = 1; i <= m; i ++) if ( q[i].r - q[i].l + 1 <= k ){
        for (int j = q[i].l; j <= q[i].r; j ++){
            if ( lef[a[j]] ) ans[q[i].id] = min(ans[q[i].id], j-lef[a[j]]);
            lef[a[j]] = j;
        }
        for (int j = q[i].l; j <= q[i].r; j ++) lef[a[j]] = 0;
    }

    int l, r, tmp, last = 0;
    stack<int> stk;
    for (int i = 1; i <= m; i ++) if ( q[i].r - q[i].l + 1 > k ){
        if ( block(q[i].l) != last ){
            memset(lef, 0, sizeof lef);
            memset(rig, 0, sizeof rig);
            last = block(q[i].l);
            l = block(q[i].l) * k;
            r = l + 1, tmp = oo;
//            cout << "chuyen block moi \n";
        }

//        cerr << "query " << q[i].l << ' ' << q[i].r << '\n';
//        cerr << l << ' ' << r << '\n';

        while ( r <= q[i].r ){
            if ( lef[a[r]] ) tmp = min(tmp, r-lef[a[r]]);
            lef[a[r]] = r;
            if ( !rig[a[r]] ) rig[a[r]] = r;
            r ++;
        }

        ans[q[i].id] = tmp;

        while ( l >= q[i].l ){
            stk.push(rig[a[l]]);
            if ( rig[a[l]] ) ans[q[i].id] = min(ans[q[i].id], rig[a[l]]-l);
            rig[a[l]] = l;
            l --;
        }

        while ( stk.size() ){
            rig[a[++l]] = stk.top();
            stk.pop();
        }
    }

    for (int i = 1; i <= m; i ++)
        cout << ( ans[i] == oo ? -1 : ans[i] ) << '\n';

    return 0;
}
