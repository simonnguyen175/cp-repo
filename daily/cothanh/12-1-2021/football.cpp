#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, k, L, R;
int win[N][N];

vector<int> Merge(int l, int r){
    vector<int> res;
    if ( l == r ){
        res.push_back(l); return res;
    }

    int mid = ( l + r ) / 2;

    vector<int> a = Merge(l, mid);
    vector<int> b = Merge(mid + 1, r);

    int i = 0, j = 0;

    while ( i < a.size() && j < b.size() ){
        if ( win[a[i]][b[j]] ) res.push_back(a[i]), i ++;
        else res.push_back(b[j]), j ++;
    }

    while ( i < a.size() ) res.push_back(a[i]), i ++;
    while ( j < b.size() ) res.push_back(b[j]), j ++;

    return res;
}

void solve(){
    cin >> L >> R;
    vector<int> ans = Merge(L, R);
    cout << R - L + 1 << ' ';
    for (int u : ans) cout << u << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("football.inp", "r") ){
        freopen("football.inp", "r", stdin);
        freopen("football.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> win[i][j];

    while ( k -- )
        solve();

    return 0;
}
