#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n, m;
int bit[N];
pi a[N], b[N];
vector<int> cont;

void update(int u){
    int id = u;
    while ( id <= (int)cont.size() ){
        bit[id] ++;
        id += (id & (-id));
    }
}

int get(int p){
    int id = p, ans = 0;
    while ( id > 0 ){
        ans += bit[id];
        id -= (id & (-id));
    }
    return ans;
}

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        cont.push_back(a[i].fi);
        cont.push_back(a[i].se);
    }

    for (int i = 1; i <= m; i ++){
        cin >> b[i].fi >> b[i].se;
        cont.push_back(b[i].fi);
        cont.push_back(b[i].se);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    sort(a + 1, a + 1 + n, greater<pi>());
    sort(b + 1, b + 1 + m, greater<pi>());

    int j = 1, ans = 0;
    for (int i = 1; i <= m; i ++){
        while ( j <= n && a[j].fi >= b[i].fi ){
//            cout << j << ' ' << a[j].se << ' ' << id(a[j].se) << '\n';
            update(id(a[j].se));
            j ++;
        }
//        cout << b[i].se << ' ' << id(b[i].se) << ' ' << get(id(b[i].se)) << '\n';
        ans = max(ans, get(id(b[i].se)));
    }

    cout << ans;

    return 0;
}
