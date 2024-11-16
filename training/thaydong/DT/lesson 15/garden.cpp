#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int MX = 1e5 + 2;
const int oo = 1e9;

int n, m;
double l;
int w;
int a[N], b[N], bit[N][N];
struct plant{
    int x, y;
    double p;
    int s;
};
vector<plant> lst1, lst2;
vector<int> contu, contd;

int idu(int x){
    return upper_bound(contu.begin(), contu.end(), x) - contu.begin();
}

int idd(int x){
    return upper_bound(contd.begin(), contd.end(), x) - contd.begin();
}

double dc(int x, int y){
    return (double)sqrt(1ll*abs(x-y)*abs(x-y) + w*w);
}

void upd(int x, int y, int val){
    for (int i = x; i <= n; i += i&-i)
    for (int j = y; j <= m; j += j&-j)
        bit[i][j] = min(bit[i][j], val);
}

int get(int x, int y){
    int res = oo;
    for (int i = x; i >= 1; i -= i&-i)
    for (int j = y; j >= 1; j -= j&-j)
        res = min(res, bit[i][j]);
    return res;
}

void solve(){
    cin >> l >> w;
    contu.clear(); contd.clear();
    lst1.clear(); lst2.clear();
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], contu.pb(a[i]);
    cin >> m;
    for (int i = 1; i <= m; i ++)
        cin >> b[i], contd.pb(b[i]);

    sort(contu.begin(), contu.end());
    contu.erase(unique(contu.begin(), contu.end()), contu.end());
    sort(contd.begin(), contd.end());
    contd.erase(unique(contd.begin(), contd.end()), contd.end());

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        double tmp = dc(a[i], b[j]);
        lst1.pb({idu(a[i]), idd(b[j]), a[i]*1.0 + b[j]*1.0 + tmp, i + j});
        lst2.pb({idu(a[i]), idd(b[j]), -a[i]*1.0 + -b[j]*1.0 + tmp, i + j - 2});
    }

    sort(lst1.begin(), lst1.end(), [&](plant a, plant b){
        return a.p > b.p;
    });
    sort(lst2.begin(), lst2.end(), [&](plant a, plant b){
        return a.p < b.p;
    });

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        bit[i][j] = oo;

    int ptr = 0;
    for (int i = 0; i < n * m; i ++){
        while ( ptr < n * m && lst2[ptr].p + lst1[i].p <= l ){
            upd(lst2[ptr].x, lst2[ptr].y, lst2[ptr].s);
            ptr ++;
        }
        ans = max(ans, lst1[i].s - get(lst1[i].x, lst1[i].y));
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
