#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
struct info{
    int fi, se, id;
} a[N];
int bit[N];
map<int, int> id;
vector<int> box[N];

int get(int u){
    int res = 0;
    for (; u <= n; u += u&-u)
        res = max(res, bit[u]);
    return res;
}

void update(int u, int v){
    for (; u >= 1; u -= u&-u)
        bit[u] = max(bit[u], v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    vector<int> cont;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
        cont.pb(a[i].se);
    }

    sort(cont.begin(), cont.end());
    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    sort(a+1, a+1+n, [](info a, info b){
        if ( a.fi != b.fi ) return a.fi < b.fi;
        else return a.se > b.se;
    });

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int tmp = get(id[a[i].se]) + 1;
        update(id[a[i].se], tmp);
        if ( !box[tmp].size() ) ans ++;
        box[tmp].pb(a[i].id);
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i ++) if ( box[i].size() ){
        reverse(box[i].begin(), box[i].end());
        cout << box[i].size() << ' ';
        for (int x : box[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
