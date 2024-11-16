#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int sub, test, n, m, s;
int a[N], mx[N];
struct coders{
    int b, c, id;
} coder[N];
vector<pi> ans;

int need(int x, int d){
    return ( x%d ? x/d+1 : x/d );
}

bool check(int d){
    int id = 1;
    int k = need(m, d);
    priority_queue<pi> heap;
    for (int i = 1; i <= m; i ++){
        while ( id <= n && coder[id].b >= a[i] ){
            if ( heap.size() == k ){
                if ( heap.top().fi > coder[id].c ){
                    heap.pop();
                    heap.push({coder[id].c, coder[id].id});
                }
            }
            else heap.push({coder[id].c, coder[id].id});
            id ++;
        }
        if ( heap.size() < need(i, d) ) return 0;
    }

    if ( heap.size() == k ){
        vector<pi> tmp;
        int sum = 0;
        while ( heap.size() ){
            int x = heap.top().se;
            tmp.pb({mx[x], x});
            sum += heap.top().fi;
            heap.pop();
        }
        if ( sum <= s ){
            ans = tmp;
            return 1;
        }
    }

    return 0;
}

void solve(){
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++) cin >> a[i];
    sort(a + 1, a + 1 + m, greater<int>());
    for (int i = 1; i <= n; i ++) cin >> coder[i].b;
    for (int i = 1; i <= n; i ++)
        cin >> coder[i].c, coder[i].id = i, mx[i] = coder[i].b;
    sort(coder + 1, coder + 1 + n, [&](coders x, coders y){
        return x.b > y.b;
    });

    ans.clear();
    int lo = 1, hi = m, res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    if ( res == -1 ) cout << "NO\n\n";
    else{
        cout << "YES\n";
        sort(ans.begin(), ans.end());
        for (auto x : ans) cout << x.se << ' ';
        cout << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("cheating.inp", "r", stdin);
    freopen("cheating.out", "w", stdout);

    cin >> sub >> test;
    while ( test -- )
        solve();

    return 0;
}
