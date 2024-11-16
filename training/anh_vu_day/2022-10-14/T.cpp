#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, m;
struct obj{
    int type, x, y, id;
};
vector<obj> cont;
int nxt[N], Par[N], Size[N], res[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Size[u] < Size[v] ) swap(u, v);
        Par[v] = u;
        Size[u] += Size[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("cowboy.inp", "r") ){
        freopen("cowboy.inp", "r", stdin);
        freopen("cowboy.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        cont.pb({0, x, y, 0});
    }

    cin >> m;
    for (int i = 1, x, y; i <= m; i ++){
        cin >> x >> y;
        cont.pb({1, x, y, i});
    }

    sort(cont.begin(), cont.end(), [&](obj a, obj b){
        if ( a.y == b.y ) return a.type > b.type;
        else return a.y > b.y;
    });

    set<pi> s;
    for (auto A : cont){
        auto it = s.lower_bound({A.x, 0});

        if ( !A.type ){
            if ( it != s.end() ) Size[it->se] ++;
        }
        else{
            if ( it != s.end() )
                nxt[A.id] = it->se;

            s.insert({A.x, A.id});
            it = s.lower_bound({A.x, A.id});
            it --;

            while ( it != s.end() ){
                if ( it->se > A.id )
                    it = s.erase(it), it --;
                else break;
            }
        }
    }

    for (int i = 1; i <= m; i ++) Par[i] = i;
    for (int i = m; i >= 1; i --){
        res[i] = Size[Find(i)];
        if ( nxt[i] ) Join(i, nxt[i]);
    }

    for (int i = 1; i <= m; i ++) cout << res[i] << '\n';

    return 0;
}
