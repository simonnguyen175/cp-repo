#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int w, h;
struct edge{
    int id, type, w;
};
vector<edge> edg;
int cnt_row[N], cnt_col[N], subrow, subcol;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("planemst.inp", "r", stdin);
    freopen("planemst.out", "w", stdout);

    cin >> w >> h;
    for (int i = 0, x; i < w; i ++){
        cin >> x;
        edg.pb({i, 0, x});
    }

    for (int i = 0, x; i < h; i ++){
        cin >> x;
        edg.pb({i, 1, x});
    }

    for (int i = 1; i <= w; i ++)
        cnt_row[i] = h + 1;
    for (int i = 1; i <= h; i ++)
        cnt_col[i] = w + 1;

    sort(edg.begin(), edg.end(), [&](edge a, edge b){
        return a.w < b.w;
    });

    ll ans = 0;

    for (auto it : edg) if ( it.type == 0 ){
        ans += 1ll * max(cnt_row[it.id] - subrow, cnt_row[it.id+1] - subrow) * it.w;
        subcol ++;
        cnt_row[it.id] = min(cnt_row[it.id], cnt_row[it.id+1]);
        cnt_row[it.id+1] = min(cnt_row[it.id], cnt_row[it.id+1]);
    }
    else{
        ans += 1ll * max(cnt_col[it.id] - subcol, cnt_col[it.id+1] - subcol) * it.w;
        subrow ++;
        cnt_col[it.id] = min(cnt_col[it.id], cnt_col[it.id+1]);
        cnt_col[it.id+1] = min(cnt_col[it.id], cnt_col[it.id+1]);
    }

    cout << ans;


    return 0;
}
