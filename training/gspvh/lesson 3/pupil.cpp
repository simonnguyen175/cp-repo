#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pi pair<ll, int>
using namespace std;
const int N = 5e5 + 5;
const int oo = 1e9;

int d, n, m, c;
struct spot{
    int pos, cost, id;

    bool operator < (const spot &a) const{
        return pos < a.pos;
    }
} spots[N];
int lg2[N], mn[N][25], trace[N];

int ckmn(int x, int y){
    return ( spots[x].cost < spots[y].cost ? x : y );
}

int getmn(int l, int r){
    int k = lg2[r-l+1];
    return ckmn(mn[l][k], mn[r-(1<<k)+1][k]);
}

pi calc(int l, int r, int s){
    if ( l == r ) return {0, s};
    if ( l + 1 == r )
        return {0LL, s - spots[r].pos + spots[l].pos};

    int mid = getmn(l + 1, r - 1);

    pi pre = calc(l, mid, s);

    int need = spots[r].pos - spots[mid].pos;

    int buy = max(0, min(n, need) - pre.se);

    trace[spots[mid].id] = buy;

    pi suf = calc(mid, r, pre.se + buy);

    ll res = pre.fi + suf.fi + 1LL * buy * spots[mid].cost;

    return {res, suf.se};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pupil.inp", "r") ){
        freopen("pupil.inp", "r", stdin);
        freopen("pupil.out", "w", stdout);
    }

    cin >> d >> n >> m >> c;

    for (int i = 1; i <= m; i ++){
        cin >> spots[i].pos >> spots[i].cost;
        spots[i].id = i;
    }

    sort(spots + 1, spots + 1 + m);
    spots[0] = {0, oo, 0};
    spots[m+1] = {d, oo, 0};

    for (int i = 1; i <= m; i ++)
        mn[i][0] = i;

    lg2[1] = 0;
    for (int i = 2; i <= m; i ++)
        lg2[i] = lg2[i/2] + 1;

    for (int j = 1; j <= lg2[m]; j ++)
        for (int i = 1; i + (1<<j) - 1<= m; i ++){
            mn[i][j] = ckmn(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        }

    for (int i = 1; i <= m + 1; i ++)
        if ( spots[i].pos - spots[i-1].pos > n ){
            cout << -1;
            return 0;
        }
    if ( spots[1].pos > c ) { cout << -1; return 0; }

    cout << calc(0, m + 1, c).fi << '\n';
    for (int i = 1; i <= m; i ++)
        cout << trace[i] << ' ';

    return 0;
}
